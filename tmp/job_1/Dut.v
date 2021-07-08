// Generator : SpinalHDL v1.5.0    git head : 83a031922866b078c411ec5529e00f1b6e79f8e7
// Component : Dut
// Git hash  : 666dcbba79181659d0c736eb931d19ec1dc17a25



module Dut (
  input      [7:0]    io_a,
  input      [7:0]    io_b,
  input      [7:0]    io_c,
  output     [7:0]    io_result
);
  wire       [7:0]    _zz_io_result;

  assign _zz_io_result = (io_a + io_b);
  assign io_result = (_zz_io_result - io_c);

endmodule
