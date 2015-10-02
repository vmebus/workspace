/*	SYN_DFF_TEST	*/
`timescale 1ns/1ns
module	SYN_DFF_TEST;
reg		D, CLK;
wire	Q, Q_B;
parameter	STEP = 50;

	SYN_DFF	SYN_DFF	(D, CLK, Q, Q_B);
	always	#(STEP/2)	CLK = ~CLK;
	initial begin
					D = 0;	CLK	= 0;
		#(1.5*STEP)	D = 1;
		#(2*STEP)	D = 0;
		#STEP		D = 1;
		#(STEP/2)	$finish;
	end
endmodule	
	