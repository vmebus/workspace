/*	Flip Flop Delay	*/
`timescale	1ns/100ps
module	FF_DELAY	(R_B, D, CLK, Q, Q_B);
input	R_B, D, CLK;
output	Q, Q_B;
reg		Q;
parameter	R_OUT = 9;
parameter	CLK_OUT	= 10.5;

	assign	Q_B = ~Q;
	always	@ (posedge CLK or negedge	R_B)
	if (!R_B)	#R_OUT		Q <= 0;
	else 		#CLK_OUT	Q <= D;
endmodule	
		
	
