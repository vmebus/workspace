/*	BCD ENC_TEST */
`timescale 1ns/1ns
module BCD_ENC_TEST;
reg		[9:0]	IN;
wire	[3:0]	OUT;
integer 	i, j;

	BCD_ENC		BCD_ENC	(IN, OUT);
	
	initial begin
	j = {5'b10001, 9'b0, 1'b1};
		for (i = 0; i <= 15; i = i + 1)
			begin 
				j = j << 1;
				IN = j [15:6];
				#100;
			end
	$finish;
	end
endmodule	
