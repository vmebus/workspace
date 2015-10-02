/* Latch */
module LAT	(D, G, Q, Q_B);
input	D, G;
output	Q, Q_B;
reg		Q;
	assign Q_B = ~Q;
	always @ (D or G)
	if (G)
		Q <= D;
endmodule		