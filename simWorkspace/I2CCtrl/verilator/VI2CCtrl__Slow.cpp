// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VI2CCtrl.h for the primary calling header

#include "VI2CCtrl.h"
#include "VI2CCtrl__Syms.h"

//==========
WData/*87:0*/ VI2CCtrl::__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[8][3];
CData/*0:0*/ VI2CCtrl::__Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[32];
CData/*0:0*/ VI2CCtrl::__Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[128];

VL_CTOR_IMP(VI2CCtrl) {
    VI2CCtrl__Syms* __restrict vlSymsp = __VlSymsp = new VI2CCtrl__Syms(this, name());
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VI2CCtrl::__Vconfigure(VI2CCtrl__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VI2CCtrl::~VI2CCtrl() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VI2CCtrl::_initial__TOP__1(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_initial__TOP__1\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_scl_read = 0U;
}

void VI2CCtrl::_settle__TOP__2(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_settle__TOP__2\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_i2c_scl_oe = 0U;
    vlTOPp->io_i2c_sda_read = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out;
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l106 
        = (0x33U != (0x7fU & ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter) 
                              >> 1U)));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l124 
        = (1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167 
        = (7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l178 
        = (0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value));
    vlTOPp->__Vtableidx1 = vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state;
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[0U] 
        = vlTOPp->__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string
        [vlTOPp->__Vtableidx1][0U];
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[1U] 
        = vlTOPp->__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string
        [vlTOPp->__Vtableidx1][1U];
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[2U] 
        = vlTOPp->__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string
        [vlTOPp->__Vtableidx1][2U];
    vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid = 0U;
    if ((4U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
        if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
            vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid = 1U;
        }
    }
    vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload = 0U;
    if ((4U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
        if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
            vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload 
                = vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter;
        }
    }
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start 
        = (((~ (IData)(vlTOPp->io_i2c_sda_write)) & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext)) 
           & (IData)(vlTOPp->io_i2c_scl_write));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall 
        = ((~ (IData)(vlTOPp->io_i2c_scl_write)) & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext));
    vlTOPp->__Vtableidx2 = (((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)) 
                             << 4U) | (((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) 
                                        << 3U) | (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state)));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready 
        = vlTOPp->__Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready
        [vlTOPp->__Vtableidx2];
    vlTOPp->io_read_valid = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid;
    vlTOPp->io_read_payload = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload;
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l92 
        = ((((IData)(vlTOPp->io_i2c_sda_write) & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1))) 
            & (IData)(vlTOPp->io_i2c_scl_write)) | 
           ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start) 
            & (0U != (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))));
    vlTOPp->__Vtableidx3 = (((0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)) 
                             << 6U) | (((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) 
                                        << 5U) | ((
                                                   (0U 
                                                    == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)) 
                                                   << 4U) 
                                                  | (((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) 
                                                      << 3U) 
                                                     | (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state)))));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out_en 
        = vlTOPp->__Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en
        [vlTOPp->__Vtableidx3];
    vlTOPp->io_write_ready = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready;
    vlTOPp->io_i2c_sda_oe = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out_en;
}

void VI2CCtrl::_eval_initial(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_eval_initial\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void VI2CCtrl::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::final\n"); );
    // Variables
    VI2CCtrl__Syms* __restrict vlSymsp = this->__VlSymsp;
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VI2CCtrl::_eval_settle(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_eval_settle\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[5U] = 1U;
    vlTOPp->__Vm_traceActivity[4U] = 1U;
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    vlTOPp->__Vm_traceActivity[2U] = 1U;
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VI2CCtrl::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_ctor_var_reset\n"); );
    // Body
    io_config_frame_addrmode = VL_RAND_RESET_I(1);
    io_write_valid = VL_RAND_RESET_I(1);
    io_write_ready = VL_RAND_RESET_I(1);
    io_write_payload = VL_RAND_RESET_I(8);
    io_read_valid = VL_RAND_RESET_I(1);
    io_read_ready = VL_RAND_RESET_I(1);
    io_read_payload = VL_RAND_RESET_I(8);
    io_i2c_sda_write = VL_RAND_RESET_I(1);
    io_i2c_sda_read = VL_RAND_RESET_I(1);
    io_i2c_scl_write = VL_RAND_RESET_I(1);
    io_i2c_scl_read = VL_RAND_RESET_I(1);
    io_i2c_sda_oe = VL_RAND_RESET_I(1);
    io_i2c_scl_oe = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1_io_write_ready = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1_io_read_valid = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1_io_read_payload = VL_RAND_RESET_I(8);
    I2CCtrl__DOT__I2cSlave_1_io_sda_out_en = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1_io_sda_out = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__edge_start = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter = VL_RAND_RESET_I(2);
    I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__sample_value = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = VL_RAND_RESET_I(3);
    I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = VL_RAND_RESET_I(3);
    I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter = VL_RAND_RESET_I(8);
    I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l92 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l106 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l124 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167 = VL_RAND_RESET_I(1);
    I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l178 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(88, I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string);
    __Vtableidx1 = 0;
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[0],0x0049444c,0x45202020,0x20202020);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[1],0x00414444,0x52202020,0x20202020);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[2],0x00414444,0x5241434b,0x20202020);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[3],0x00545241,0x4e534d49,0x54202020);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[4],0x00524543,0x45495645,0x20202020);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[5],0x00545241,0x4e534d49,0x5441434b);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[6],0x00524543,0x45495645,0x41434b20);
    VL_CONST_W_3X(88,__Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[7],0x003f3f3f,0x3f3f3f3f,0x3f3f3f3f);
    __Vtableidx2 = 0;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[0] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[1] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[2] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[3] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[4] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[5] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[6] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[7] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[8] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[9] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[10] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[11] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[12] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[13] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[14] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[15] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[16] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[17] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[18] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[19] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[20] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[21] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[22] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[23] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[24] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[25] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[26] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[27] = 1U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[28] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[29] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[30] = 0U;
    __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[31] = 0U;
    __Vtableidx3 = 0;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[0] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[1] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[2] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[3] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[4] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[5] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[6] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[7] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[8] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[9] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[10] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[11] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[12] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[13] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[14] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[15] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[16] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[17] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[18] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[19] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[20] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[21] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[22] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[23] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[24] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[25] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[26] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[27] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[28] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[29] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[30] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[31] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[32] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[33] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[34] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[35] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[36] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[37] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[38] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[39] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[40] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[41] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[42] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[43] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[44] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[45] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[46] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[47] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[48] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[49] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[50] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[51] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[52] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[53] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[54] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[55] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[56] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[57] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[58] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[59] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[60] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[61] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[62] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[63] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[64] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[65] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[66] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[67] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[68] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[69] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[70] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[71] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[72] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[73] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[74] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[75] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[76] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[77] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[78] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[79] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[80] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[81] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[82] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[83] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[84] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[85] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[86] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[87] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[88] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[89] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[90] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[91] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[92] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[93] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[94] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[95] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[96] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[97] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[98] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[99] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[100] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[101] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[102] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[103] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[104] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[105] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[106] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[107] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[108] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[109] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[110] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[111] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[112] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[113] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[114] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[115] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[116] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[117] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[118] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[119] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[120] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[121] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[122] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[123] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[124] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[125] = 0U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[126] = 1U;
    __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[127] = 1U;
    __Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = VL_RAND_RESET_I(3);
    __Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<6; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
