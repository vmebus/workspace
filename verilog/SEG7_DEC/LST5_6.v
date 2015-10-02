/*	SEG7 DEC_TEST */
`timescale 1ns/1ns
module SEG7_DEC_TEST;
reg		[3:0]	IN;
wire	[6:0]	OUT;

integer 	i;

	SEG7_DEC		SEG7_DEC	(IN, OUT);
	
	initial begin
	IN = 0;
		for (i = 0; i <= 15; i = i + 1)
				#50		IN = IN + 1;
	$finish;
	end
endmodule	
