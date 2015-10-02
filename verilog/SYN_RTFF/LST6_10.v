/*	SYN_RTFF_TEST	*/
`timescale 1ns/1ns
module	SYN_RTFF_TEST;
reg		R, T, CLK;
wire	Q, Q_B;
parameter	STEP = 50;

	SYN_RTFF	SYN_RTFF	(R, T, CLK, Q, Q_B);
	always	#(STEP/2)	CLK = ~CLK;
	initial begin
					R = 0;	T = 0;	CLK	= 1;
		#(STEP/2)	R = 1;
		#(STEP/4)	R = 0;
		#STEP				T = 1;
		#(1.5*STEP)			T = 0;
		#(1.5*STEP)			T = 1;
		#(STEP/2)	$finish;
	end
endmodule	
	