`timescale	1ns/1ns
module	CNT100_TEST;
reg	RESET_B, CLK, LOAD, EN, UP;
reg	[7:0] IN;
wire	CNT_99;
wire	[7:0] Q;
parameter	STEP = 100;

	CNT100	CNT100	( RESET_B, CLK, LOAD, EN, UP, IN, Q, CNT_99 );
	always	#( STEP/2 )	CLK = ~CLK;
	initial
		begin
				RESET_B = 1; CLK = 0; LOAD = 0;
				EN = 1;      UP = 1;  
				IN[7:4] = 9; IN[3:0] = 5;
		#( STEP/10 )	LOAD = 1;
		#STEP		LOAD = 0;
		#STEP		EN   = 1; IN = 8'bx;
		#STEP		EN   = 0;
		#( 2*STEP )	EN   = 1;
		#( 3*STEP )	EN   = 0;
		#STEP		EN   = 1;
		#( 4*STEP )	UP   = 0;
		#( 7*STEP )	$finish;
	end
endmodule
