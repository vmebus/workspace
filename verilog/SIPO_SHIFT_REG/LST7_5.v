/* Serail in parallel out shift register */
module	SIPO_SHIFT_REG	(RESET_B, IN, CLK, Q);
input	RESET_B, CLK, IN;
output	[3:0]	Q;
reg 	[3:0]	Q;

	always	@	(posedge CLK, or negedge RESET_B)
		Q <= (!RESET_B) ? 0 : {Q, IN};

endmodule		