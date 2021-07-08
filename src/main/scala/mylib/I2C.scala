package mylib

import spinal.core._
import spinal.lib._
import spinal.lib.io.ReadableOpenDrain

//import scala.collection.mutable.ArrayBuffer
//import scala.util.Random
//import spinal.core.internals.Operator
//import spinal.lib.fsm._
//import spinal.lib.FragmentToBitsStates._
//import spinal.lib.experimental.math._


/* i2c bus interface , here try readableopendrain  */
case class I2c() extends Bundle with IMasterSlave {
  val sda   = ReadableOpenDrain(Bool)
  val scl   = ReadableOpenDrain(Bool)
  val sda_oe = out Bool
  val scl_oe = out Bool
  override def asMaster(): Unit = {
    master(scl)
    master(sda)
  }
  override def asSlave(): Unit = {
    slave(scl)
    slave(sda)
  }
}

object  I2CMasterSlaveType extends  SpinalEnum(binarySequential){
  val MASTER,SLAVE = newElement()
}

object I2CAddrModeType extends  SpinalEnum(binarySequential){
  val SEVEN,TEN = newElement()
}

object I2CCtrlSlaveState extends SpinalEnum{
  val IDLE,ADDR,ADDRACK,TRANSMIT,RECEIVE,TRANSMITACK,RECEIVEACK = newElement()
}
