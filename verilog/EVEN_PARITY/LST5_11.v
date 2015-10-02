/* EVEN PARITY TEST */
`timescale 1ns/1ns
module EVEN_PARITY_TEST;
reg [3:0]	IN;
wire		ODD_OUT;
integer		i;

	EVEN_PARITY		EVEN_PARITY(IN, ODD_OUT);

	initial begin
	IN = 0;
	for (i =0; i <= 15; i = i + 1)
		#50 	IN = IN + 1;
		$finish;
	end
endmodule	