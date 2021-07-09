package mylib

import spinal.core._
import spinal.lib._
import I2CMasterSlaveType._
import I2CAddrModeType._
import spinal.lib.fsm._

//import scala.collection.mutable.ArrayBuffer
//import spinal.core.internals.Operator
//import spinal.lib.FragmentToBitsStates._
//import spinal.lib.experimental.math._


class I2CSlave(g:I2CCtrlGenerics) extends Component{
  import g._
  val io = new Bundle{
    val configFrame  = in(I2CFrameConfig(g))
    val write        = slave Stream (Bits(8 bit))
    val read	     = master Stream (Bits(8 bit))
    val scl          = in Bool
    val sda_out_en   = out Bool
    val scl_out_en   = out Bool
    val sda_out      = RegInit(True).asOutput
    val sda_in	     = in Bool
  }
  /* temp */

  io.write.ready := False
  io.read.payload := B"8'x0"
  io.read.valid := False
  io.sda_out_en := False
  io.scl_out_en := False
  //io.sda_out := True


  val edge = new Area {
    /* start/stop edge detect && sda sampling */
    val sclFall = io.scl.fall(initAt = False)
    val sclRise = io.scl.rise(initAt = False)
    val sdaFall = io.sda_in.fall(initAt = False)
    val sdaRise = io.sda_in.rise(initAt = False)
    val start = sdaFall && io.scl
    val stop = sdaRise && io.scl
  }

  val sample = new Area {
    /* sda delayed sample */
    val Counter = Reg(UInt(log2Up(g.sampleDelay) bit))
    val finish_ff = Counter === (g.sampleDelay - 1)
	val finish = RegNext(finish_ff)
    val Enable = Reg(Bool, False)
    val value = RegNextWhen(io.sda_in,finish_ff,False)

    when(edge.sclRise) {
      Enable := True
    }.elsewhen(finish) {
      Enable := False
    }

    when(finish) {
      Counter := 0
    }.elsewhen(Enable) {
      Counter := Counter + 1
    }
  }


  /* bit counter */
  val bitCounter = new Area {
    val value = Reg(UInt(3 bits))
    def reset() = value := 0

    when(sample.finish) {
      when(value === 7) {
        value := 0
      }.otherwise {
        value := value + 1
      }
    }
  }

  /* state machine */

  val stateMachine = new Area{
    import I2CCtrlSlaveState._
    val state = RegInit(IDLE)
    val shifter = Reg(io.read.payload,B"8'h0") /* rx shifter */
    val DeviceID = B"7'h33"

    //TODO
    when(edge.stop || (edge.start && (state =/= IDLE))){state := IDLE}

    switch(state){
      is(IDLE){
        when(edge.start){
          state := ADDR
          bitCounter.reset()
        }
      }

      is(ADDR){
        when(sample.finish){
          shifter(7 - bitCounter.value) := sample.value
          when(bitCounter.value === 7){
            when(shifter(7 downto 1) =/= DeviceID){
              state := IDLE
            }.otherwise{
              state := ADDRACK
            }
          }
        }
      }

      is(ADDRACK){
        when(edge.sclFall === True){
          when(bitCounter.value === 0){
            io.sda_out_en := True
            io.sda_out := !io.write.valid
			}
		}
		when(sample.finish === True){
            bitCounter.reset()
            when(shifter(0) === True){
              when(io.write.valid === True){
                state := TRANSMIT
              }.otherwise{
                state := IDLE
              }
            }.otherwise{
              state := RECEIVE
            }
         }
      }

      is(TRANSMIT){
        io.sda_out_en := True
		when(edge.sclFall){
        	io.sda_out := io.write.payload(7 - bitCounter.value)
		}
        when(sample.finish === True){
          when(bitCounter.value === 7){
            io.write.ready := True
            bitCounter.reset()
            state := TRANSMITACK
          }
        }
      }

      is(TRANSMITACK){
        when(sample.finish === True){
          when(io.sda_in === True){ //no ack
            state := IDLE
          }.otherwise{
            when(io.write.valid){ //TODO now stop transmit completely when bot valid
              state := TRANSMIT
            }.otherwise{
              state := IDLE
            }
          }
        }
      }

      is(RECEIVE){
        when(sample.finish){
          shifter(7 - bitCounter.value) := sample.value
          when(bitCounter.value === 7){
            bitCounter.reset()
            state := RECEIVEACK
          }
        }
      }

      is(RECEIVEACK){
        io.read.valid := True
        io.read.payload := shifter
        when(edge.sclFall === True){
          when(bitCounter.value === 0){
            io.sda_out_en := True
            io.sda_out := !io.read.ready
          }.otherwise{
            bitCounter.reset()
            io.sda_out := True
            when(io.read.ready === True){ //TODO now stop receive completely when not ready
              state := RECEIVE
            }.otherwise{
              state := IDLE
            }
          }
        }
      }
    }
  }




  /* signal output */


}
