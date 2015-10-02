/*	DIV_TEST	*/
`timescale	1ns/1ns
module	DIV_TEST;
reg	[7:0]	DD;
reg	[3:0]	DQ;
reg		START, CLOCK, RESET_B;
wire	[7:0]	ANS;
wire	[3:0]	ARE;
parameter	STEP = 100;

	DIV	DIV	( DD, DQ, ANS, ARE, START, CLOCK, RESET_B );

	always	#( STEP / 2 )	CLOCK = ~CLOCK;

	initial
		begin
			RESET_B = 1; CLOCK = 1; DD = 8'b10011101; DQ = 4'b1011; START = 0;
			# ( STEP / 10 )		RESET_B = 0;
			# ( STEP / 10 )		RESET_B = 1;
			# STEP			START = 1;
			# STEP			START = 0;
			# ( 10 * STEP )		$finish;
		end
endmodule
