// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VI2CCtrl.h for the primary calling header

#include "VI2CCtrl.h"
#include "VI2CCtrl__Syms.h"

//==========

void VI2CCtrl::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VI2CCtrl::eval\n"); );
    VI2CCtrl__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiayizhang/workplace/i2c_lab/tmp/job_1/I2CCtrl.v", 20, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VI2CCtrl::_eval_initial_loop(VI2CCtrl__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/home/jiayizhang/workplace/i2c_lab/tmp/job_1/I2CCtrl.v", 20, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__3(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__3\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
        = vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state;
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->io_i2c_sda_write));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->io_i2c_sda_write));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->io_i2c_scl_write));
    if (vlTOPp->reset) {
        vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out = 1U;
        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = 0U;
        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter = 0U;
    } else {
        if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l92) {
            vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = 0U;
        }
        if ((4U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
            if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) {
                    if ((0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out 
                            = (1U & (~ (IData)(vlTOPp->io_read_ready)));
                    } else {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out = 1U;
                        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
                            = ((IData)(vlTOPp->io_read_ready)
                                ? 4U : 0U);
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
                            = ((IData)(vlTOPp->io_i2c_sda_write)
                                ? 0U : ((IData)(vlTOPp->io_write_valid)
                                         ? 3U : 0U));
                    }
                } else {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter 
                            = (((~ ((IData)(1U) << 
                                    (7U & ((IData)(7U) 
                                           - (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))))) 
                                & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter)) 
                               | ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value) 
                                  << (7U & ((IData)(7U) 
                                            - (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)))));
                        if ((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))) {
                            vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = 6U;
                        }
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                if ((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out 
                            = (1U & ((IData)(vlTOPp->io_write_payload) 
                                     >> (7U & ((IData)(7U) 
                                               - (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)))));
                    }
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                        if ((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))) {
                            vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = 5U;
                        }
                    }
                } else {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) {
                        if ((0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))) {
                            vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out 
                                = (1U & (~ (IData)(vlTOPp->io_write_valid)));
                        }
                    }
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
                            = ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l124)
                                ? ((IData)(vlTOPp->io_write_valid)
                                    ? 3U : 0U) : 4U);
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter 
                            = (((~ ((IData)(1U) << 
                                    (7U & ((IData)(7U) 
                                           - (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))))) 
                                & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter)) 
                               | ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value) 
                                  << (7U & ((IData)(7U) 
                                            - (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)))));
                        if ((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))) {
                            vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
                                = ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l106)
                                    ? 0U : 2U);
                        }
                    }
                } else {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start) {
                        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->io_i2c_sda_read = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out;
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__4(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__4\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l106 
        = (0x33U != (0x7fU & ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter) 
                              >> 1U)));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l124 
        = (1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter));
    if (vlTOPp->reset) {
        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value = 0U;
    } else {
        if ((3U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter))) {
            vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_value 
                = vlTOPp->io_i2c_sda_write;
        }
    }
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__5(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__5\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter 
        = vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter;
    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
        vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter = 0U;
    } else {
        if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable) {
            vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter 
                = (3U & ((IData)(1U) + (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter)));
        }
    }
    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value 
            = ((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167)
                ? 0U : (7U & ((IData)(1U) + (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value))));
    }
    if ((4U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
        if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
            if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall) {
                if ((1U & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l178)))) {
                    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = 0U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state)))) {
                if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = 0U;
                    }
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
            if ((1U & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state))) {
                if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                    if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167) {
                        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = 0U;
                    }
                }
            } else {
                if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = 0U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state)))) {
                if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start) {
                    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value = 0U;
                }
            }
        }
    }
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167 
        = (7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l178 
        = (0U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value));
}

VL_INLINE_OPT void VI2CCtrl::_combo__TOP__6(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_combo__TOP__6\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_start 
        = (((~ (IData)(vlTOPp->io_i2c_sda_write)) & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext)) 
           & (IData)(vlTOPp->io_i2c_scl_write));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall 
        = ((~ (IData)(vlTOPp->io_i2c_scl_write)) & (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext));
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__7(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__7\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state 
        = vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state;
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
    if (vlTOPp->reset) {
        vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable = 0U;
    } else {
        if (((IData)(vlTOPp->io_i2c_scl_write) & (~ (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1)))) {
            vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable = 1U;
        } else {
            if (vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) {
                vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable = 0U;
            }
        }
    }
    vlTOPp->io_read_valid = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_valid;
    vlTOPp->io_read_payload = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_read_payload;
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->io_i2c_scl_write));
}

VL_INLINE_OPT void VI2CCtrl::_combo__TOP__8(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_combo__TOP__8\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->io_i2c_sda_oe = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_sda_out_en;
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__9(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__9\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish 
        = (3U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter 
        = vlTOPp->__Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter;
}

VL_INLINE_OPT void VI2CCtrl::_sequent__TOP__10(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_sequent__TOP__10\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx2 = (((7U == (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value)) 
                             << 4U) | (((IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish) 
                                        << 3U) | (IData)(vlTOPp->I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state)));
    vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready 
        = vlTOPp->__Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready
        [vlTOPp->__Vtableidx2];
    vlTOPp->io_write_ready = vlTOPp->I2CCtrl__DOT__I2cSlave_1_io_write_ready;
}

void VI2CCtrl::_eval(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_eval\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__reset))))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData VI2CCtrl::_change_request(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_change_request\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VI2CCtrl::_change_request_1(VI2CCtrl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_change_request_1\n"); );
    VI2CCtrl* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VI2CCtrl::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VI2CCtrl::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((io_config_frame_addrmode & 0xfeU))) {
        Verilated::overWidthError("io_config_frame_addrmode");}
    if (VL_UNLIKELY((io_write_valid & 0xfeU))) {
        Verilated::overWidthError("io_write_valid");}
    if (VL_UNLIKELY((io_read_ready & 0xfeU))) {
        Verilated::overWidthError("io_read_ready");}
    if (VL_UNLIKELY((io_i2c_sda_write & 0xfeU))) {
        Verilated::overWidthError("io_i2c_sda_write");}
    if (VL_UNLIKELY((io_i2c_scl_write & 0xfeU))) {
        Verilated::overWidthError("io_i2c_scl_write");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
