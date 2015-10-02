`timescale	1ns/1ns
module	LD_EN_UDCNT10_TEST;
reg	RESET_B, CLK, LOAD, EN, UP;
reg		[3:0] IN;
wire	[3:0] Q;
parameter	STEP = 100;
	LD_EN_UDCNT10	LD_EN_UDCNT10	( RESET_B, CLK, LOAD,  EN, UP, IN, Q );
	always	#( STEP/2 )	CLK = ~CLK;
	initial
		begin
						RESET_B = 1; CLK = 0;	LOAD = 0;	EN = 1;	UP = 1;	IN = 3;
		#( STEP/10 )							LOAD = 1;
		#STEP									LOAD = 0;
		#STEP												EN = 1;			IN = 4'bx;	
		#STEP												EN = 0;
		#(2*STEP)											EN = 1;
		#(3*STEP)											EN = 0;
		#STEP												EN = 1;
		#(4*STEP)													UP = 0;
		#(5*STEP )	$finish;
	end
endmodule
