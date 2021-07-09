// Generator : SpinalHDL v1.5.0    git head : 83a031922866b078c411ec5529e00f1b6e79f8e7
// Component : I2CCtrl
// Git hash  : 821921f5e69784a06a09e7fbff150f7b3a96b565


`define I2CAddrModeType_defaultEncoding_type [0:0]
`define I2CAddrModeType_defaultEncoding_SEVEN 1'b0
`define I2CAddrModeType_defaultEncoding_TEN 1'b1

`define I2CCtrlSlaveState_defaultEncoding_type [2:0]
`define I2CCtrlSlaveState_defaultEncoding_IDLE 3'b000
`define I2CCtrlSlaveState_defaultEncoding_ADDR 3'b001
`define I2CCtrlSlaveState_defaultEncoding_ADDRACK 3'b010
`define I2CCtrlSlaveState_defaultEncoding_TRANSMIT 3'b011
`define I2CCtrlSlaveState_defaultEncoding_RECEIVE 3'b100
`define I2CCtrlSlaveState_defaultEncoding_TRANSMITACK 3'b101
`define I2CCtrlSlaveState_defaultEncoding_RECEIVEACK 3'b110


module I2CCtrl (
  input      `I2CAddrModeType_defaultEncoding_type io_config_frame_addrmode,
  input               io_write_valid,
  output              io_write_ready,
  input      [7:0]    io_write_payload,
  output              io_read_valid,
  input               io_read_ready,
  output     [7:0]    io_read_payload,
  input               io_i2c_sda_write,
  output              io_i2c_sda_read,
  input               io_i2c_scl_write,
  output              io_i2c_scl_read,
  output              io_i2c_sda_oe,
  output              io_i2c_scl_oe,
  input               clk,
  input               reset
);
  wire                I2cSlave_1_io_write_ready;
  wire                I2cSlave_1_io_read_valid;
  wire       [7:0]    I2cSlave_1_io_read_payload;
  wire                I2cSlave_1_io_sda_out_en;
  wire                I2cSlave_1_io_scl_out_en;
  wire                I2cSlave_1_io_sda_out;
  `ifndef SYNTHESIS
  reg [39:0] io_config_frame_addrmode_string;
  `endif


  I2CSlave I2cSlave_1 (
    .io_configFrame_addrmode    (io_config_frame_addrmode    ), //i
    .io_write_valid             (io_write_valid              ), //i
    .io_write_ready             (I2cSlave_1_io_write_ready   ), //o
    .io_write_payload           (io_write_payload            ), //i
    .io_read_valid              (I2cSlave_1_io_read_valid    ), //o
    .io_read_ready              (io_read_ready               ), //i
    .io_read_payload            (I2cSlave_1_io_read_payload  ), //o
    .io_scl                     (io_i2c_scl_write            ), //i
    .io_sda_out_en              (I2cSlave_1_io_sda_out_en    ), //o
    .io_scl_out_en              (I2cSlave_1_io_scl_out_en    ), //o
    .io_sda_out                 (I2cSlave_1_io_sda_out       ), //o
    .io_sda_in                  (io_i2c_sda_write            ), //i
    .clk                        (clk                         ), //i
    .reset                      (reset                       )  //i
  );
  `ifndef SYNTHESIS
  always @(*) begin
    case(io_config_frame_addrmode)
      `I2CAddrModeType_defaultEncoding_SEVEN : io_config_frame_addrmode_string = "SEVEN";
      `I2CAddrModeType_defaultEncoding_TEN : io_config_frame_addrmode_string = "TEN  ";
      default : io_config_frame_addrmode_string = "?????";
    endcase
  end
  `endif

  assign io_write_ready = I2cSlave_1_io_write_ready;
  assign io_read_valid = I2cSlave_1_io_read_valid;
  assign io_read_payload = I2cSlave_1_io_read_payload;
  assign io_i2c_sda_read = I2cSlave_1_io_sda_out;
  assign io_i2c_sda_oe = I2cSlave_1_io_sda_out_en;
  assign io_i2c_scl_oe = I2cSlave_1_io_scl_out_en;
  assign io_i2c_scl_read = 1'b0;

endmodule

module I2CSlave (
  input      `I2CAddrModeType_defaultEncoding_type io_configFrame_addrmode,
  input               io_write_valid,
  output reg          io_write_ready,
  input      [7:0]    io_write_payload,
  output reg          io_read_valid,
  input               io_read_ready,
  output reg [7:0]    io_read_payload,
  input               io_scl,
  output reg          io_sda_out_en,
  output              io_scl_out_en,
  output reg          io_sda_out,
  input               io_sda_in,
  input               clk,
  input               reset
);
  wire       [2:0]    _zz_stateMachine_shifter;
  wire       [2:0]    _zz_io_sda_out;
  wire       [2:0]    _zz_stateMachine_shifter_1;
  reg                 io_scl_regNext;
  wire                edge_sclFall;
  reg                 io_scl_regNext_1;
  wire                edge_sclRise;
  reg                 io_sda_in_regNext;
  wire                edge_sdaFall;
  reg                 io_sda_in_regNext_1;
  wire                edge_sdaRise;
  wire                edge_start;
  wire                edge_stop;
  reg        [1:0]    sample_Counter;
  wire                sample_finish_ff;
  reg                 sample_finish;
  reg                 sample_Enable;
  reg                 sample_value;
  reg        [2:0]    bitCounter_value;
  wire                when_I2CSlave_l75;
  reg        `I2CCtrlSlaveState_defaultEncoding_type stateMachine_state;
  reg        [7:0]    stateMachine_shifter;
  wire       [6:0]    stateMachine_DeviceID;
  wire                when_I2CSlave_l92;
  wire                when_I2CSlave_l105;
  wire                when_I2CSlave_l106;
  wire                when_I2CSlave_l116;
  wire                when_I2CSlave_l117;
  wire                when_I2CSlave_l122;
  wire                when_I2CSlave_l124;
  wire                when_I2CSlave_l125;
  wire                when_I2CSlave_l141;
  wire                when_I2CSlave_l142;
  wire                when_I2CSlave_l151;
  wire                when_I2CSlave_l152;
  wire                when_I2CSlave_l167;
  wire                when_I2CSlave_l177;
  wire                when_I2CSlave_l178;
  wire                when_I2CSlave_l184;
  `ifndef SYNTHESIS
  reg [39:0] io_configFrame_addrmode_string;
  reg [87:0] stateMachine_state_string;
  `endif


  assign _zz_stateMachine_shifter = (3'b111 - bitCounter_value);
  assign _zz_io_sda_out = (3'b111 - bitCounter_value);
  assign _zz_stateMachine_shifter_1 = (3'b111 - bitCounter_value);
  `ifndef SYNTHESIS
  always @(*) begin
    case(io_configFrame_addrmode)
      `I2CAddrModeType_defaultEncoding_SEVEN : io_configFrame_addrmode_string = "SEVEN";
      `I2CAddrModeType_defaultEncoding_TEN : io_configFrame_addrmode_string = "TEN  ";
      default : io_configFrame_addrmode_string = "?????";
    endcase
  end
  always @(*) begin
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : stateMachine_state_string = "IDLE       ";
      `I2CCtrlSlaveState_defaultEncoding_ADDR : stateMachine_state_string = "ADDR       ";
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : stateMachine_state_string = "ADDRACK    ";
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : stateMachine_state_string = "TRANSMIT   ";
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : stateMachine_state_string = "RECEIVE    ";
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : stateMachine_state_string = "TRANSMITACK";
      `I2CCtrlSlaveState_defaultEncoding_RECEIVEACK : stateMachine_state_string = "RECEIVEACK ";
      default : stateMachine_state_string = "???????????";
    endcase
  end
  `endif

  always @(*) begin
    io_write_ready = 1'b0;
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
        if(when_I2CSlave_l141) begin
          if(when_I2CSlave_l142) begin
            io_write_ready = 1'b1;
          end
        end
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
      end
      default : begin
      end
    endcase
  end

  always @(*) begin
    io_read_payload = 8'h0;
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
      end
      default : begin
        io_read_payload = stateMachine_shifter;
      end
    endcase
  end

  always @(*) begin
    io_read_valid = 1'b0;
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
      end
      default : begin
        io_read_valid = 1'b1;
      end
    endcase
  end

  always @(*) begin
    io_sda_out_en = 1'b0;
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
        if(when_I2CSlave_l116) begin
          if(when_I2CSlave_l117) begin
            io_sda_out_en = 1'b1;
          end
        end
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
        io_sda_out_en = 1'b1;
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
      end
      default : begin
        if(when_I2CSlave_l177) begin
          if(when_I2CSlave_l178) begin
            io_sda_out_en = 1'b1;
          end
        end
      end
    endcase
  end

  assign io_scl_out_en = 1'b0;
  assign edge_sclFall = ((! io_scl) && io_scl_regNext);
  assign edge_sclRise = (io_scl && (! io_scl_regNext_1));
  assign edge_sdaFall = ((! io_sda_in) && io_sda_in_regNext);
  assign edge_sdaRise = (io_sda_in && (! io_sda_in_regNext_1));
  assign edge_start = (edge_sdaFall && io_scl);
  assign edge_stop = (edge_sdaRise && io_scl);
  assign sample_finish_ff = (sample_Counter == 2'b11);
  assign when_I2CSlave_l75 = (bitCounter_value == 3'b111);
  assign stateMachine_DeviceID = 7'h33;
  assign when_I2CSlave_l92 = (edge_stop || (edge_start && (stateMachine_state != `I2CCtrlSlaveState_defaultEncoding_IDLE)));
  assign when_I2CSlave_l105 = (bitCounter_value == 3'b111);
  assign when_I2CSlave_l106 = (stateMachine_shifter[7 : 1] != stateMachine_DeviceID);
  assign when_I2CSlave_l116 = (edge_sclFall == 1'b1);
  assign when_I2CSlave_l117 = (bitCounter_value == 3'b000);
  assign when_I2CSlave_l122 = (sample_finish == 1'b1);
  assign when_I2CSlave_l124 = (stateMachine_shifter[0] == 1'b1);
  assign when_I2CSlave_l125 = (io_write_valid == 1'b1);
  assign when_I2CSlave_l141 = (sample_finish == 1'b1);
  assign when_I2CSlave_l142 = (bitCounter_value == 3'b111);
  assign when_I2CSlave_l151 = (sample_finish == 1'b1);
  assign when_I2CSlave_l152 = (io_sda_in == 1'b1);
  assign when_I2CSlave_l167 = (bitCounter_value == 3'b111);
  assign when_I2CSlave_l177 = (edge_sclFall == 1'b1);
  assign when_I2CSlave_l178 = (bitCounter_value == 3'b000);
  assign when_I2CSlave_l184 = (io_read_ready == 1'b1);
  always @(posedge clk or posedge reset) begin
    if(reset) begin
      io_sda_out <= 1'b1;
      io_scl_regNext <= 1'b0;
      io_scl_regNext_1 <= 1'b0;
      io_sda_in_regNext <= 1'b0;
      io_sda_in_regNext_1 <= 1'b0;
      sample_Enable <= 1'b0;
      sample_value <= 1'b0;
      stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
      stateMachine_shifter <= 8'h0;
    end else begin
      io_scl_regNext <= io_scl;
      io_scl_regNext_1 <= io_scl;
      io_sda_in_regNext <= io_sda_in;
      io_sda_in_regNext_1 <= io_sda_in;
      if(sample_finish_ff) begin
        sample_value <= io_sda_in;
      end
      if(edge_sclRise) begin
        sample_Enable <= 1'b1;
      end else begin
        if(sample_finish) begin
          sample_Enable <= 1'b0;
        end
      end
      if(when_I2CSlave_l92) begin
        stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
      end
      case(stateMachine_state)
        `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
          if(edge_start) begin
            stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_ADDR;
          end
        end
        `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
          if(sample_finish) begin
            stateMachine_shifter[_zz_stateMachine_shifter] <= sample_value;
            if(when_I2CSlave_l105) begin
              if(when_I2CSlave_l106) begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
              end else begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_ADDRACK;
              end
            end
          end
        end
        `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
          if(when_I2CSlave_l116) begin
            if(when_I2CSlave_l117) begin
              io_sda_out <= (! io_write_valid);
            end
          end
          if(when_I2CSlave_l122) begin
            if(when_I2CSlave_l124) begin
              if(when_I2CSlave_l125) begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_TRANSMIT;
              end else begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
              end
            end else begin
              stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_RECEIVE;
            end
          end
        end
        `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
          if(edge_sclFall) begin
            io_sda_out <= io_write_payload[_zz_io_sda_out];
          end
          if(when_I2CSlave_l141) begin
            if(when_I2CSlave_l142) begin
              stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK;
            end
          end
        end
        `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
          if(when_I2CSlave_l151) begin
            if(when_I2CSlave_l152) begin
              stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
            end else begin
              if(io_write_valid) begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_TRANSMIT;
              end else begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
              end
            end
          end
        end
        `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
          if(sample_finish) begin
            stateMachine_shifter[_zz_stateMachine_shifter_1] <= sample_value;
            if(when_I2CSlave_l167) begin
              stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_RECEIVEACK;
            end
          end
        end
        default : begin
          if(when_I2CSlave_l177) begin
            if(when_I2CSlave_l178) begin
              io_sda_out <= (! io_read_ready);
            end else begin
              io_sda_out <= 1'b1;
              if(when_I2CSlave_l184) begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_RECEIVE;
              end else begin
                stateMachine_state <= `I2CCtrlSlaveState_defaultEncoding_IDLE;
              end
            end
          end
        end
      endcase
    end
  end

  always @(posedge clk) begin
    sample_finish <= sample_finish_ff;
    if(sample_finish) begin
      sample_Counter <= 2'b00;
    end else begin
      if(sample_Enable) begin
        sample_Counter <= (sample_Counter + 2'b01);
      end
    end
    if(sample_finish) begin
      if(when_I2CSlave_l75) begin
        bitCounter_value <= 3'b000;
      end else begin
        bitCounter_value <= (bitCounter_value + 3'b001);
      end
    end
    case(stateMachine_state)
      `I2CCtrlSlaveState_defaultEncoding_IDLE : begin
        if(edge_start) begin
          bitCounter_value <= 3'b000;
        end
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDR : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_ADDRACK : begin
        if(when_I2CSlave_l122) begin
          bitCounter_value <= 3'b000;
        end
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMIT : begin
        if(when_I2CSlave_l141) begin
          if(when_I2CSlave_l142) begin
            bitCounter_value <= 3'b000;
          end
        end
      end
      `I2CCtrlSlaveState_defaultEncoding_TRANSMITACK : begin
      end
      `I2CCtrlSlaveState_defaultEncoding_RECEIVE : begin
        if(sample_finish) begin
          if(when_I2CSlave_l167) begin
            bitCounter_value <= 3'b000;
          end
        end
      end
      default : begin
        if(when_I2CSlave_l177) begin
          if(!when_I2CSlave_l178) begin
            bitCounter_value <= 3'b000;
          end
        end
      end
    endcase
  end


endmodule
