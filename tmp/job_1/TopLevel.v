// Generator : SpinalHDL v1.5.0    git head : 83a031922866b078c411ec5529e00f1b6e79f8e7
// Component : TopLevel
// Git hash  : 666dcbba79181659d0c736eb931d19ec1dc17a25



module TopLevel (
  input               clk,
  input               reset
);
  reg        [7:0]    counter /* verilator public */ ;

  always @(posedge clk or posedge reset) begin
    if(reset) begin
      counter <= 8'h0;
    end else begin
      counter <= (counter + 8'h01);
    end
  end


endmodule
