/* REG4_TEST */
`timescale 1ns/1ns
module	REG4_TEST;
reg		CLR_B, CLK;
reg	[3:0]	D;
wire [3:0]	Q;
parameter	STEP = 100;

	REG4	REG4	(CLR_B, D, CLK, Q);
	always	#(STEP/2)	CLK = ~CLK;
	initial begin
				CLR_B = 1;	D = 0;	CLK = 0;
	#(STEP/5)	CLR_B = 0;
	#(STEP/5)	CLR_B = 1;
	#(STEP*3/5)				D = 4'b1110;
	#STEP					D = 4'b1011;
	#STEP					D = 4'b0011;
	#STEP					D = 4'b0100;
	#(STEP/2-10)	$finish;
	end
endmodule	