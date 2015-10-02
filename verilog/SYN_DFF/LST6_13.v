/* Synchronization D Flip Flop */
module	SYN_DFF	(D, CLK, Q, Q_B);
input	D, CLK;
output	Q, Q_B;
reg 	Q;

	assign	Q_B = ~Q;
	always	@(posedge CLK)
		Q <= D;
endmodule		
