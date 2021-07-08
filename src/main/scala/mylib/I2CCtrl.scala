package mylib

import spinal.core._
import spinal.lib._
import I2CMasterSlaveType._
import I2CAddrModeType._
import spinal.lib.FragmentToBitsStates._
import spinal.lib.bus.misc.{BusSlaveFactoryAddressWrapper, BusSlaveFactory}

//import spinal.lib.bus.misc.{BusSlaveFactoryAddressWrapper, BusSlaveFactory} //TODO BUS

//import scala.collection.mutable.ArrayBuffer
//import spinal.core.internals.Operator
//import spinal.lib.fsm._
//import spinal.lib.FragmentToBitsStates._
//import spinal.lib.experimental.math._

/* Controller construction parameters , to be exteneded */
case class I2CCtrlGenerics(
                          clockDivider: Int = 8, //for master to generate
                          sampleDelay: Int = 4
                          ){

}

case class I2CFrameConfig(g:I2CCtrlGenerics) extends Bundle{
  val addrmode = I2CAddrModeType()
}

case class I2CCtrlConfig(g: I2CCtrlGenerics) extends Bundle{
  val frame = I2CFrameConfig(g)
  //val clockDivider = xxx /* TODO For master */
}

class I2CCtrl(g:I2CCtrlGenerics = I2CCtrlGenerics()) extends Component{
  val io = new Bundle{
    val config = in(I2CCtrlConfig(g))
    val write = slave(Stream(Bits(8 bits)))
    val read = master(Stream(Bits(8 bits)))
    val i2c = slave(I2c())
  }
  /* slave instance */
  val I2cSlave = new I2CSlave(g)

  /* clock divider TODO for Master */

  /* port connect */
  I2cSlave.io.configFrame := io.config.frame
  I2cSlave.io.write << io.write
  I2cSlave.io.read >> io.read
  I2cSlave.io.sda_in <> io.i2c.sda.write
  I2cSlave.io.sda_out <> io.i2c.sda.read
  I2cSlave.io.scl <> io.i2c.scl.write
  I2cSlave.io.sda_out_en <> io.i2c.sda_oe
  I2cSlave.io.scl_out_en <> io.i2c.scl_oe
  io.i2c.scl.read := False /* TODO just for slave  */

}


object I2Ctop{
  val config = new I2CCtrlGenerics()
  def main(args:Array[String]): Unit ={
    SpinalConfig(
      mode = Verilog,
      defaultClockDomainFrequency=FixedFrequency(50 MHz)
    ).generate(new I2CCtrl(config))
  }
}
