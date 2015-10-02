/* Parellel input serial output shift register */
module	PISO_SHIFT_REG (LOAD, IN, CLK, Q);
input	LOAD, CLK;
input	[3:0]	IN;
output	[3:0]	Q;
reg 	[3:0]	Q;

	always	@	(posedge CLK or posedge LOAD)
	if (LOAD)	Q <= IN;
	else		Q <= Q << 1;

endmodule	
	