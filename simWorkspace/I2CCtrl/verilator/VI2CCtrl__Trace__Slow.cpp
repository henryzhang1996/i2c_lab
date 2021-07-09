// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VI2CCtrl__Syms.h"


//======================

void VI2CCtrl::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VI2CCtrl::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VI2CCtrl::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VI2CCtrl::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VI2CCtrl::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBus(c+26,"io_config_frame_addrmode", false,-1, 0,0);
        tracep->declBit(c+27,"io_write_valid", false,-1);
        tracep->declBit(c+28,"io_write_ready", false,-1);
        tracep->declBus(c+29,"io_write_payload", false,-1, 7,0);
        tracep->declBit(c+30,"io_read_valid", false,-1);
        tracep->declBit(c+31,"io_read_ready", false,-1);
        tracep->declBus(c+32,"io_read_payload", false,-1, 7,0);
        tracep->declBit(c+33,"io_i2c_sda_write", false,-1);
        tracep->declBit(c+34,"io_i2c_sda_read", false,-1);
        tracep->declBit(c+35,"io_i2c_scl_write", false,-1);
        tracep->declBit(c+36,"io_i2c_scl_read", false,-1);
        tracep->declBit(c+37,"io_i2c_sda_oe", false,-1);
        tracep->declBit(c+38,"io_i2c_scl_oe", false,-1);
        tracep->declBit(c+39,"clk", false,-1);
        tracep->declBit(c+40,"reset", false,-1);
        tracep->declBus(c+26,"I2CCtrl io_config_frame_addrmode", false,-1, 0,0);
        tracep->declBit(c+27,"I2CCtrl io_write_valid", false,-1);
        tracep->declBit(c+28,"I2CCtrl io_write_ready", false,-1);
        tracep->declBus(c+29,"I2CCtrl io_write_payload", false,-1, 7,0);
        tracep->declBit(c+30,"I2CCtrl io_read_valid", false,-1);
        tracep->declBit(c+31,"I2CCtrl io_read_ready", false,-1);
        tracep->declBus(c+32,"I2CCtrl io_read_payload", false,-1, 7,0);
        tracep->declBit(c+33,"I2CCtrl io_i2c_sda_write", false,-1);
        tracep->declBit(c+34,"I2CCtrl io_i2c_sda_read", false,-1);
        tracep->declBit(c+35,"I2CCtrl io_i2c_scl_write", false,-1);
        tracep->declBit(c+36,"I2CCtrl io_i2c_scl_read", false,-1);
        tracep->declBit(c+37,"I2CCtrl io_i2c_sda_oe", false,-1);
        tracep->declBit(c+38,"I2CCtrl io_i2c_scl_oe", false,-1);
        tracep->declBit(c+39,"I2CCtrl clk", false,-1);
        tracep->declBit(c+40,"I2CCtrl reset", false,-1);
        tracep->declBit(c+41,"I2CCtrl I2cSlave_1_io_write_ready", false,-1);
        tracep->declBit(c+15,"I2CCtrl I2cSlave_1_io_read_valid", false,-1);
        tracep->declBus(c+16,"I2CCtrl I2cSlave_1_io_read_payload", false,-1, 7,0);
        tracep->declBit(c+12,"I2CCtrl I2cSlave_1_io_sda_out_en", false,-1);
        tracep->declBit(c+49,"I2CCtrl I2cSlave_1_io_scl_out_en", false,-1);
        tracep->declBit(c+1,"I2CCtrl I2cSlave_1_io_sda_out", false,-1);
        tracep->declQuad(c+42,"I2CCtrl io_config_frame_addrmode_string", false,-1, 39,0);
        tracep->declBus(c+26,"I2CCtrl I2cSlave_1 io_configFrame_addrmode", false,-1, 0,0);
        tracep->declBit(c+27,"I2CCtrl I2cSlave_1 io_write_valid", false,-1);
        tracep->declBit(c+41,"I2CCtrl I2cSlave_1 io_write_ready", false,-1);
        tracep->declBus(c+29,"I2CCtrl I2cSlave_1 io_write_payload", false,-1, 7,0);
        tracep->declBit(c+15,"I2CCtrl I2cSlave_1 io_read_valid", false,-1);
        tracep->declBit(c+31,"I2CCtrl I2cSlave_1 io_read_ready", false,-1);
        tracep->declBus(c+16,"I2CCtrl I2cSlave_1 io_read_payload", false,-1, 7,0);
        tracep->declBit(c+35,"I2CCtrl I2cSlave_1 io_scl", false,-1);
        tracep->declBit(c+12,"I2CCtrl I2cSlave_1 io_sda_out_en", false,-1);
        tracep->declBit(c+49,"I2CCtrl I2cSlave_1 io_scl_out_en", false,-1);
        tracep->declBit(c+1,"I2CCtrl I2cSlave_1 io_sda_out", false,-1);
        tracep->declBit(c+33,"I2CCtrl I2cSlave_1 io_sda_in", false,-1);
        tracep->declBit(c+39,"I2CCtrl I2cSlave_1 clk", false,-1);
        tracep->declBit(c+40,"I2CCtrl I2cSlave_1 reset", false,-1);
        tracep->declBit(c+2,"I2CCtrl I2cSlave_1 io_scl_regNext", false,-1);
        tracep->declBit(c+13,"I2CCtrl I2cSlave_1 edge_sclFall", false,-1);
        tracep->declBit(c+17,"I2CCtrl I2cSlave_1 io_scl_regNext_1", false,-1);
        tracep->declBit(c+44,"I2CCtrl I2cSlave_1 edge_sclRise", false,-1);
        tracep->declBit(c+3,"I2CCtrl I2cSlave_1 io_sda_in_regNext", false,-1);
        tracep->declBit(c+45,"I2CCtrl I2cSlave_1 edge_sdaFall", false,-1);
        tracep->declBit(c+4,"I2CCtrl I2cSlave_1 io_sda_in_regNext_1", false,-1);
        tracep->declBit(c+46,"I2CCtrl I2cSlave_1 edge_sdaRise", false,-1);
        tracep->declBit(c+14,"I2CCtrl I2cSlave_1 edge_start", false,-1);
        tracep->declBit(c+47,"I2CCtrl I2cSlave_1 edge_stop", false,-1);
        tracep->declBus(c+23,"I2CCtrl I2cSlave_1 sample_Counter", false,-1, 1,0);
        tracep->declBit(c+24,"I2CCtrl I2cSlave_1 sample_finish_ff", false,-1);
        tracep->declBit(c+25,"I2CCtrl I2cSlave_1 sample_finish", false,-1);
        tracep->declBit(c+18,"I2CCtrl I2cSlave_1 sample_Enable", false,-1);
        tracep->declBit(c+5,"I2CCtrl I2cSlave_1 sample_value", false,-1);
        tracep->declBus(c+9,"I2CCtrl I2cSlave_1 bitCounter_value", false,-1, 2,0);
        tracep->declBit(c+10,"I2CCtrl I2cSlave_1 when_I2CSlave_l75", false,-1);
        tracep->declBus(c+19,"I2CCtrl I2cSlave_1 stateMachine_state", false,-1, 2,0);
        tracep->declBus(c+6,"I2CCtrl I2cSlave_1 stateMachine_shifter", false,-1, 7,0);
        tracep->declBus(c+50,"I2CCtrl I2cSlave_1 stateMachine_DeviceID", false,-1, 6,0);
        tracep->declBit(c+48,"I2CCtrl I2cSlave_1 when_I2CSlave_l92", false,-1);
        tracep->declBit(c+10,"I2CCtrl I2cSlave_1 when_I2CSlave_l105", false,-1);
        tracep->declBit(c+7,"I2CCtrl I2cSlave_1 when_I2CSlave_l106", false,-1);
        tracep->declBit(c+13,"I2CCtrl I2cSlave_1 when_I2CSlave_l116", false,-1);
        tracep->declBit(c+11,"I2CCtrl I2cSlave_1 when_I2CSlave_l117", false,-1);
        tracep->declBit(c+25,"I2CCtrl I2cSlave_1 when_I2CSlave_l122", false,-1);
        tracep->declBit(c+8,"I2CCtrl I2cSlave_1 when_I2CSlave_l124", false,-1);
        tracep->declBit(c+27,"I2CCtrl I2cSlave_1 when_I2CSlave_l125", false,-1);
        tracep->declBit(c+25,"I2CCtrl I2cSlave_1 when_I2CSlave_l141", false,-1);
        tracep->declBit(c+10,"I2CCtrl I2cSlave_1 when_I2CSlave_l142", false,-1);
        tracep->declBit(c+25,"I2CCtrl I2cSlave_1 when_I2CSlave_l151", false,-1);
        tracep->declBit(c+33,"I2CCtrl I2cSlave_1 when_I2CSlave_l152", false,-1);
        tracep->declBit(c+10,"I2CCtrl I2cSlave_1 when_I2CSlave_l167", false,-1);
        tracep->declBit(c+13,"I2CCtrl I2cSlave_1 when_I2CSlave_l177", false,-1);
        tracep->declBit(c+11,"I2CCtrl I2cSlave_1 when_I2CSlave_l178", false,-1);
        tracep->declBit(c+31,"I2CCtrl I2cSlave_1 when_I2CSlave_l184", false,-1);
        tracep->declQuad(c+42,"I2CCtrl I2cSlave_1 io_configFrame_addrmode_string", false,-1, 39,0);
        tracep->declArray(c+20,"I2CCtrl I2cSlave_1 stateMachine_state_string", false,-1, 87,0);
    }
}

void VI2CCtrl::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VI2CCtrl::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VI2CCtrl::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VI2CCtrl__Syms* __restrict vlSymsp = static_cast<VI2CCtrl__Syms*>(userp);
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out));
        tracep->fullBit(oldp+2,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext));
        tracep->fullBit(oldp+3,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext));
        tracep->fullBit(oldp+4,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1));
        tracep->fullBit(oldp+5,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value));
        tracep->fullCData(oldp+6,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter),8);
        tracep->fullBit(oldp+7,((0x33U != (0x7fU & 
                                           ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter) 
                                            >> 1U)))));
        tracep->fullBit(oldp+8,((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter))));
        tracep->fullCData(oldp+9,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value),3);
        tracep->fullBit(oldp+10,((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))));
        tracep->fullBit(oldp+11,((0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))));
        tracep->fullBit(oldp+12,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out_en));
        tracep->fullBit(oldp+13,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall));
        tracep->fullBit(oldp+14,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start));
        tracep->fullBit(oldp+15,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid));
        tracep->fullCData(oldp+16,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload),8);
        tracep->fullBit(oldp+17,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1));
        tracep->fullBit(oldp+18,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable));
        tracep->fullCData(oldp+19,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state),3);
        tracep->fullWData(oldp+20,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string),88);
        tracep->fullCData(oldp+23,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter),2);
        tracep->fullBit(oldp+24,((3U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter))));
        tracep->fullBit(oldp+25,(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish));
        tracep->fullBit(oldp+26,(vlTOPp->io_config_frame_addrmode));
        tracep->fullBit(oldp+27,(vlTOPp->io_write_valid));
        tracep->fullBit(oldp+28,(vlTOPp->io_write_ready));
        tracep->fullCData(oldp+29,(vlTOPp->io_write_payload),8);
        tracep->fullBit(oldp+30,(vlTOPp->io_read_valid));
        tracep->fullBit(oldp+31,(vlTOPp->io_read_ready));
        tracep->fullCData(oldp+32,(vlTOPp->io_read_payload),8);
        tracep->fullBit(oldp+33,(vlTOPp->io_i2c_sda_write));
        tracep->fullBit(oldp+34,(vlTOPp->io_i2c_sda_read));
        tracep->fullBit(oldp+35,(vlTOPp->io_i2c_scl_write));
        tracep->fullBit(oldp+36,(vlTOPp->io_i2c_scl_read));
        tracep->fullBit(oldp+37,(vlTOPp->io_i2c_sda_oe));
        tracep->fullBit(oldp+38,(vlTOPp->io_i2c_scl_oe));
        tracep->fullBit(oldp+39,(vlTOPp->clk));
        tracep->fullBit(oldp+40,(vlTOPp->reset));
        tracep->fullBit(oldp+41,(vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready));
        tracep->fullQData(oldp+42,(((IData)(vlTOPp->io_config_frame_addrmode)
                                     ? ((IData)(vlTOPp->io_config_frame_addrmode)
                                         ? 0x54454e2020ULL
                                         : 0x3f3f3f3f3fULL)
                                     : 0x534556454eULL)),40);
        tracep->fullBit(oldp+44,(((IData)(vlTOPp->io_i2c_scl_write) 
                                  & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1)))));
        tracep->fullBit(oldp+45,(((~ (IData)(vlTOPp->io_i2c_sda_write)) 
                                  & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext))));
        tracep->fullBit(oldp+46,(((IData)(vlTOPp->io_i2c_sda_write) 
                                  & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1)))));
        tracep->fullBit(oldp+47,((((IData)(vlTOPp->io_i2c_sda_write) 
                                   & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1))) 
                                  & (IData)(vlTOPp->io_i2c_scl_write))));
        tracep->fullBit(oldp+48,(((((IData)(vlTOPp->io_i2c_sda_write) 
                                    & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1))) 
                                   & (IData)(vlTOPp->io_i2c_scl_write)) 
                                  | ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start) 
                                     & (0U != (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))))));
        tracep->fullBit(oldp+49,(0U));
        tracep->fullCData(oldp+50,(0x33U),7);
    }
}
