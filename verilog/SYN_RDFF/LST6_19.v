/* SYN_RDFF_TEST	*/
`timescale	1ns/1ns
module	SYN_RDFF_TEST;
reg		R_B, D, CLK;
wire	Q, Q_B;
parameter	STEP = 50;

	SYN_RDFF	SYN_RDFF	(R_B, D, CLK, Q, Q_B);
	
	always #(STEP/2)	CLK = ~CLK;
	initial	begin
					R_B = 1;	D = 0;	CLK = 0;
		#(STEP/4)	R_B = 0;
		#(STEP*3/4)			D = 1;
		#(STEP/4)	R_B = 1;
		#(2*STEP)			D = 0;
		#STEP				D = 1;
		#(STEP/2)	R_B = 0;
		#(STEP/2)   R_B = 1;
		#(STEP/4)	$finish;
	end
endmodule	