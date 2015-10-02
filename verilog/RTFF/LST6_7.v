/*	RT Flip Flop */
module 	RTFF		(R, T, Q, Q_B);
input		R,T;
output	Q, Q_B;
reg		Q;

	assign	Q_B = ~Q;
	always	@(posedge R or posedge T)
		Q <= (R) ? 0:~Q;
endmodule		
