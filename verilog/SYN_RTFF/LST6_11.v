/* Synchronization T Flip Flop with asynchronization R*/
module	SYN_RTFF	(R, T, CLK, Q, Q_B);
input	R, T, CLK;
output	Q, Q_B;
reg 	Q;

	assign	Q_B = ~Q;
	always	@(posedge CLK or posedge R)
	if (R)	Q <= 0;
	else if (T)		Q <= ~Q;
endmodule		
