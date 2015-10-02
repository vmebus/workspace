/*	EN_REG4_TEST */
`timescale	1ns/1ns
module	EN_REG4_TEST;
reg	CLR_B, CLK, EN;
reg		[3:0] D;
wire	[3:0] Q;
parameter	STEP = 100;

	EN_REG4		EN_REG4	( CLR_B, D, CLK, EN, Q );
	
	always	#( STEP/2 )	CLK = ~CLK;
	initial	begin
						CLR_B = 1; 	D = 0;  	 EN = 0; CLK = 0;
		#(STEP/5 )		CLR_B = 0;
		#(STEP/5 )		CLR_B = 1;
		#(STEP*3/5 )				D = 4'b1110; EN = 1;
		#STEP						D = 4'b1011; EN = 0;
		#STEP						D = 4'b0011;
		#STEP						D = 4'b0100;
		#STEP									 EN = 1;
		#STEP						D = 0;		 EN = 0;
		#STEP		$finish;
	end
endmodule
