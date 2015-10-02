`timescale	1ns/1ns
module	TRAP_CNT10_TEST;
reg	RESET_B, CLK;
reg	T_FLAG;
wire	TEST;
wire	[3:0] Q;
parameter	STEP = 100;
	TRAP_CNT10	TRAP_CNT10	( RESET_B, CLK, TEST, Q );
	always	#( STEP/2 )	CLK = ~CLK;
	always	@( Q )
		if ( Q ==9 )
			T_FLAG <= 1;
	assign	TEST = ( Q == 1 ) & T_FLAG;
	initial
		begin
				RESET_B = 1; CLK = 0; T_FLAG = 0;
		#( STEP/10 )	RESET_B = 0;
		#( STEP/5 )	RESET_B = 1;
		#( 20*STEP )	$finish;
	end
endmodule
