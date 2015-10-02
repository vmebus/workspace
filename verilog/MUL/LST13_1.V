/*	MUL_TEST	*/
`timescale	1ns/1ns
module	MUL_TEST;
reg	[3:0]	MD, MQ;
reg		START, CLOCK, RESET_B;
wire	[7:0]	ANS;
parameter	STEP = 100;

	MUL	MUL	( MD, MQ, ANS, START, CLOCK, RESET_B );

	always	#( STEP / 2 )	CLOCK = ~CLOCK;

	initial
		begin
			RESET_B = 1; CLOCK = 1; MD = 4'b1001; MQ = 4'b1011; START = 0;
			# ( STEP / 10 )		RESET_B = 0;
			# ( STEP / 10 )		RESET_B = 1;
			# STEP			START = 1;
			# STEP			START = 0;
			# ( 6 * STEP )		MD = 4'b0110; MQ = 4'b0011; START = 1;
			# STEP			START = 0;
			# STEP			$finish;
		end
endmodule