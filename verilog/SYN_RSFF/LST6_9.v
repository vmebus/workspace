/* Synchronization RS Flip Flop */
module	SYN_RSFF	(R, S, CLK, Q, Q_B);
input	R, S, CLK;
output	Q, Q_B;
reg		Q;
	assign	Q_B = ~Q;
	always	@	(posedge CLK)
	case	({R,S})
		1: Q <= 1;
		2: Q <= 0;
		3: Q <= 1'bx;
	endcase
endmodule	
 