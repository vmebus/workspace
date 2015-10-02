`timescale	1ns/1ns
module	SW_DEF_TEST;
reg	RESET_B, CLK, SW_INPUT;
wire	[3:0] Q;
parameter	STEP = 100;

	SW_DEF	SW_DEF	( RESET_B, CLK, SW_INPUT, Q );
	always	#( STEP/2 )	CLK = ~CLK;
	initial
		begin
				RESET_B  = 1; CLK = 0; SW_INPUT = 0;
		#( STEP/10 )	RESET_B  = 0;
		#( STEP/10 )	RESET_B  = 1;
		#( 2*STEP )	SW_INPUT = 1;
		#( 6*STEP )	SW_INPUT = 0;
		#( 2*STEP )	$finish;
	end
endmodule
