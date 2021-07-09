// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VI2CCTRL_H_
#define _VI2CCTRL_H_  // guard

#include "verilated.h"

//==========

class VI2CCtrl__Syms;
class VI2CCtrl_VerilatedVcd;


//----------

VL_MODULE(VI2CCtrl) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_config_frame_addrmode,0,0);
    VL_IN8(io_write_valid,0,0);
    VL_OUT8(io_write_ready,0,0);
    VL_IN8(io_write_payload,7,0);
    VL_OUT8(io_read_valid,0,0);
    VL_IN8(io_read_ready,0,0);
    VL_OUT8(io_read_payload,7,0);
    VL_IN8(io_i2c_sda_write,0,0);
    VL_OUT8(io_i2c_sda_read,0,0);
    VL_IN8(io_i2c_scl_write,0,0);
    VL_OUT8(io_i2c_scl_read,0,0);
    VL_OUT8(io_i2c_sda_oe,0,0);
    VL_OUT8(io_i2c_scl_oe,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1_io_write_ready;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1_io_read_valid;
    CData/*7:0*/ I2CCtrl__DOT__I2cSlave_1_io_read_payload;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1_io_sda_out_en;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1_io_sda_out;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__edge_sclFall;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__io_scl_regNext_1;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__io_sda_in_regNext_1;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__edge_start;
    CData/*1:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__sample_finish;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__sample_Enable;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__sample_value;
    CData/*2:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__bitCounter_value;
    CData/*2:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state;
    CData/*7:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_shifter;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l92;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l106;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l124;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l167;
    CData/*0:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__when_I2CSlave_l178;
    WData/*87:0*/ I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[3];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*2:0*/ __Vtableidx1;
    CData/*4:0*/ __Vtableidx2;
    CData/*6:0*/ __Vtableidx3;
    CData/*2:0*/ __Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state;
    CData/*1:0*/ __Vdly__I2CCtrl__DOT__I2cSlave_1__DOT__sample_Counter;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vm_traceActivity[6];
    static WData/*87:0*/ __Vtable1_I2CCtrl__DOT__I2cSlave_1__DOT__stateMachine_state_string[8][3];
    static CData/*0:0*/ __Vtable2_I2CCtrl__DOT__I2cSlave_1_io_write_ready[32];
    static CData/*0:0*/ __Vtable3_I2CCtrl__DOT__I2cSlave_1_io_sda_out_en[128];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VI2CCtrl__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VI2CCtrl);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VI2CCtrl(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VI2CCtrl();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VI2CCtrl__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VI2CCtrl__Syms* symsp, bool first);
  private:
    static QData _change_request(VI2CCtrl__Syms* __restrict vlSymsp);
    static QData _change_request_1(VI2CCtrl__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__6(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _combo__TOP__8(VI2CCtrl__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VI2CCtrl__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VI2CCtrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VI2CCtrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VI2CCtrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__10(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(VI2CCtrl__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VI2CCtrl__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
