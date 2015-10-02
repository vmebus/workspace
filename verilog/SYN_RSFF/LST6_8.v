/* SYN_RSFF_TEST */
`timescale 1ns/1ns
module	SYN_RSFF_TEST;
reg		R, S, CLK;
wire	Q, Q_B;
parameter	STEP = 50;

	SYN_RSFF	SYN_RSFF	(R, S, CLK, Q, Q_B);
	
	always	#(STEP/2) 	CLK = ~CLK;
	initial begin
						R = 0;	S = 0; CLK = 1;	
		#(2*STEP-10)	R = 1;
		#(STEP/2)		R = 0;
		#(STEP/2)				S = 1;
		#STEP			R = 1;
		#(STEP/2)				S = 0;
		#STEP			R = 0;
		#STEP			$finish;
	end
endmodule	