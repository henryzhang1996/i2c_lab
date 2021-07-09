package mylib

import spinal.core._
import spinal.sim._
import spinal.core.sim._
import I2CMasterSlaveType._
import I2CAddrModeType._
import spinal.lib.FragmentToBitsStates._
import spinal.lib.bus.misc.{BusSlaveFactoryAddressWrapper, BusSlaveFactory}

import scala.util.Random






object I2CSim {
    val spinalConfig = SpinalConfig(defaultClockDomainFrequency = FixedFrequency(1 MHz))

    def main(args: Array[String]) {
        SimConfig
            .withConfig(spinalConfig)
            .withWave
            .compile(new I2CCtrl)
            .doSim{ dut =>
            //Fork a process to generate the reset and the clock on the dut
			dut.clockDomain.forkStimulus(period = 10000)
			dut.io.write.payload #= 0x66
			dut.io.write.valid #= true
			dut.io.read.ready #= true
			//def MasterSend(value: Int): Unit = {
			//	for(i<-0 to 7){
			//		dut.clockDomain.waitRisingEdge(1000)
			//		dut.io.i2c.sda.write #= value(7-i).toBoolean  // 1
			//		//dut.io.i2c.sda.write #= !dut.io.i2c.sda.write.toBoolean
			//		dut.clockDomain.waitRisingEdge(1000)
			//	}
			//}

			//test
			/* master => slave */
			/*
			//start
			dut.io.i2c.scl.write #= true 
			dut.io.i2c.sda.write #= true 
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.sda.write #= !dut.io.i2c.sda.write.toBoolean //start
			//address //write
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= false 
			//write 7 addr bit MSB 0x33 0110011
			
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 1
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 2
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 3
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 4
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 5
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 6
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 7
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // write
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			//check slave ack
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(500)
			if(dut.io.i2c.sda.read.toBoolean == false){
				println("SLAVE ACK!!!")
			}else{
				println("SLAVE NO ACK!!!")
			}
			dut.clockDomain.waitRisingEdge(1500)
			dut.io.i2c.scl.write #= false 
			
			//write data 8'b10100101
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 1
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 2
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 3
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 4
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 5
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 6
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 7
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 8
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			//check slave ack
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(500)
			if(dut.io.i2c.sda.read.toBoolean == false){
				println("SLAVE ACK!!!")
			}else{
				println("SLAVE NO ACK!!!")
			}
			dut.clockDomain.waitRisingEdge(1500)
			dut.io.i2c.scl.write #= false 
			
			//check data TODO
			//if(dut.io.read.payload)
			*/
	
			/* slave => master */
			//start
			dut.io.i2c.scl.write #= true 
			dut.io.i2c.sda.write #= true 
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.sda.write #= !dut.io.i2c.sda.write.toBoolean //start
			//address //write
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= false 
			//write 7 addr bit MSB 0x33 0110011
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 1
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 2
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 3
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 4
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= false  // 5
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 6
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // 7
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.sda.write #= true  // read
			dut.clockDomain.waitRisingEdge(1000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false 

			//check slave ack
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(500)
			if(dut.io.i2c.sda.read.toBoolean == false){
				println("SLAVE ACK!!!")
			}else{
				println("SLAVE NO ACK!!!")
			}
			dut.clockDomain.waitRisingEdge(1500)
			dut.io.i2c.scl.write #= false 

			//wait slave send sda data
			for(i<-0 to 7){
				dut.clockDomain.waitRisingEdge(2000)
				dut.io.i2c.scl.write #= true
				dut.clockDomain.waitRisingEdge(2000)
				dut.io.i2c.scl.write #= false
			}

			//send ack to slave
			dut.clockDomain.waitRisingEdge(500)
			dut.io.i2c.sda.write #= false  // ack
			dut.clockDomain.waitRisingEdge(1500)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= true
			dut.clockDomain.waitRisingEdge(2000)
			dut.io.i2c.scl.write #= false


			}
        }
}

