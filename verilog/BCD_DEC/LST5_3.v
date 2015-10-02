/*	BCD DEC_TEST */
`timescale 1ns/1ns
module BCD_DEC_TEST;
reg		[3:0]	IN;
wire	[9:0]	OUT;
wire  	ERR;
integer 	i;

	BCD_DEC		BCD_DEC	(IN, OUT, ERR);
	
	initial begin
	IN = 0;
		for (i = 0; i <= 15; i = i + 1)
				#50		IN = IN + 1;
	$finish;
	end
endmodule	
