/*	Enable CNT10	*/
module	EN_CNT10	( RESET_B, CLK, EN, Q );
input	RESET_B, CLK, EN;
output	[3:0] Q;
reg	[3:0] Q;
	always	@( posedge CLK or negedge RESET_B )
		if ( !RESET_B )
			Q <= 0;
		else if (EN)	
			if ( Q == 9 )
				Q <= 0;
			else
				Q <= Q + 1;
endmodule
