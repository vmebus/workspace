/* Synchronization D Flip Flop with Async R */
module SYN_RDFF	(R_B, D, CLK, Q, Q_B);
input	R_B, D, CLK;
output	Q, Q_B;
reg		Q;
	assign Q_B = ~Q;
	always @ (posedge CLK or negedge R_B)
		Q <= (!R_B) ? 0 : D;
endmodule		