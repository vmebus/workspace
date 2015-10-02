/* FF_DELAY_TEST*/
`timescale	1ns/100ps
module	FF_DELAY_TEST;
reg		R_B, D, CLK;
wire	Q, Q_B;
parameter	STEP = 50;

	FF_DELAY	FF_DELAY 	(R_B, D, CLK, Q, Q_B);

	always	#(STEP/2) CLK = ~CLK;
	initial	begin
					R_B = 1;	D = 0;	CLK =0;
		#(STEP/5)	R_B = 0;	
		#(STEP/2)				D = 1;
		#(STEP/5)	R_B = 1;
		#(1.5*STEP-10)			D = 0;
		#STEP		$finish;
	end
endmodule	