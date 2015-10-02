`timescale	1ns/1ns
module	EN_UDCNT10_TEST;
reg	RESET_B, CLK, EN, UP;
wire	[3:0] Q;
parameter	STEP = 100;
	EN_UDCNT10	EN_UDCNT10	( RESET_B, CLK, EN, UP, Q );
	always	#( STEP/2 )	CLK = ~CLK;
	initial
		begin
						RESET_B = 1; CLK = 0;	EN =1;	UP = 1;
		#( STEP/10 )	RESET_B = 0;
		#( STEP/5 )		RESET_B = 1;
		#STEP									EN = 1;
		#STEP									EN = 0;
		#(2*STEP)								EN = 1;
		#(3*STEP)								EN = 0;
		#STEP									EN = 1;
		#(7*STEP)										UP = 0;
		#(5*STEP )	$finish;
	end
endmodule
