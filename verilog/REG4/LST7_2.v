/*	REG 4 	*/
module	REG4	(CLR_B, D, CLK, Q);
input	CLR_B, CLK;
input	[3:0]	D;
output	[3:0]	Q;
reg		[3:0]	Q;

	always	@(posedge CLK or negedge CLR_B)
	Q <=	(!CLR_B) ? 0 : D;
endmodule	