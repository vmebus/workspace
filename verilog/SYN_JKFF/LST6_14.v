/* 	SYN_JKFF_TEST	*/
`timescale	1ns/1ns
module	SYN_JKFF_TEST;
reg		J,K, CLK;
wire	Q, Q_B;
parameter 	STEP = 50;

	SYN_JKFF	SYN_JKFF	(J, K, CLK, Q, Q_B);

	always	#(STEP/2)	CLK = ~CLK;
	initial begin
						J = 0;	K = 0;	CLK = 0;
		#(STEP/2-10)	J = 1;
		#STEP					K = 1;		
		#(STEP/2)		J = 0;
		#(STEP/2)				K = 0;
		#STEP					K = 1;
		#STEP			J = 1;  K = 0;
		#(STEP/2)		$finish;
	end
endmodule	
		