/* SYNC_CNT10	*/
module	SYNC_CNT10	(RESET_B, CLK, Q);
input	RESET_B, CLK;
output	[3:0]	Q;
reg		[3:0]	Q;

	always	@	(posedge CLK)
	if (!RESET_B)		Q <= 0;
	else if (Q == 9) 	Q <= 0;
	else				Q <= Q + 1;
endmodule	
	