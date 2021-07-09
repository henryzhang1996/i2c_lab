// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2CCtrl__Syms.h"


void VI2CCtrl::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VI2CCtrl::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out));
            tracep->chgBit(oldp+1,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext));
            tracep->chgBit(oldp+2,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext));
            tracep->chgBit(oldp+3,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1));
            tracep->chgBit(oldp+4,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value));
            tracep->chgCData(oldp+5,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter),8);
            tracep->chgBit(oldp+6,((0x33U != (0x7fU 
                                              & ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter) 
                                                 >> 1U)))));
            tracep->chgBit(oldp+7,((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+8,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value),3);
            tracep->chgBit(oldp+9,((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))));
            tracep->chgBit(oldp+10,((0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgBit(oldp+11,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out_en));
            tracep->chgBit(oldp+12,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall));
            tracep->chgBit(oldp+13,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgBit(oldp+14,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid));
            tracep->chgCData(oldp+15,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload),8);
            tracep->chgBit(oldp+16,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1));
            tracep->chgBit(oldp+17,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable));
            tracep->chgCData(oldp+18,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state),3);
            tracep->chgWData(oldp+19,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string),88);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgCData(oldp+22,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter),2);
            tracep->chgBit(oldp+23,((3U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter))));
            tracep->chgBit(oldp+24,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish));
        }
        tracep->chgBit(oldp+25,(vlTOPp->io_config_frame_addrmode));
        tracep->chgBit(oldp+26,(vlTOPp->io_write_valid));
        tracep->chgBit(oldp+27,(vlTOPp->io_write_ready));
        tracep->chgCData(oldp+28,(vlTOPp->io_write_payload),8);
        tracep->chgBit(oldp+29,(vlTOPp->io_read_valid));
        tracep->chgBit(oldp+30,(vlTOPp->io_read_ready));
        tracep->chgCData(oldp+31,(vlTOPp->io_read_payload),8);
        tracep->chgBit(oldp+32,(vlTOPp->io_i2c_sda_write));
        tracep->chgBit(oldp+33,(vlTOPp->io_i2c_sda_read));
        tracep->chgBit(oldp+34,(vlTOPp->io_i2c_scl_write));
        tracep->chgBit(oldp+35,(vlTOPp->io_i2c_scl_read));
        tracep->chgBit(oldp+36,(vlTOPp->io_i2c_sda_oe));
        tracep->chgBit(oldp+37,(vlTOPp->io_i2c_scl_oe));
        tracep->chgBit(oldp+38,(vlTOPp->clk));
        tracep->chgBit(oldp+39,(vlTOPp->reset));
        tracep->chgBit(oldp+40,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready));
        tracep->chgQData(oldp+41,(((IData)(vlTOPp->io_config_frame_addrmode)
                                    ? ((IData)(vlTOPp->io_config_frame_addrmode)
                                        ? 0x54454e2020ULL
                                        : 0x3f3f3f3f3fULL)
                                    : 0x534556454eULL)),40);
        tracep->chgBit(oldp+43,(((IData)(vlTOPp->io_i2c_scl_write) 
                                 & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1)))));
        tracep->chgBit(oldp+44,(((~ (IData)(vlTOPp->io_i2c_sda_write)) 
                                 & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext))));
        tracep->chgBit(oldp+45,(((IData)(vlTOPp->io_i2c_sda_write) 
                                 & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1)))));
        tracep->chgBit(oldp+46,((((IData)(vlTOPp->io_i2c_sda_write) 
                                  & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1))) 
                                 & (IData)(vlTOPp->io_i2c_scl_write))));
        tracep->chgBit(oldp+47,(((((IData)(vlTOPp->io_i2c_sda_write) 
                                   & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1))) 
                                  & (IData)(vlTOPp->io_i2c_scl_write)) 
                                 | ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start) 
                                    & (0U != (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))))));
    }
}

void VI2CCtrl::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
    }
}
