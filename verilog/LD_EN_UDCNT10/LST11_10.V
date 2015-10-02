/*	Load Enable Up Down CNT10	*/
module	LD_EN_UDCNT10	( RESET_B, CLK, LOAD, EN, UP, IN, Q );
input	RESET_B, CLK, LOAD, EN, UP;
input	[3:0] IN;
output	[3:0] Q;
reg	[3:0] Q;
	always	@( posedge CLK or negedge RESET_B )
		if ( !RESET_B )
			Q <= 0;
		else if (LOAD)
			Q <= IN;
		else if (EN)	
			if (UP)
				if ( Q == 9 )
					Q <= 0;
				else
					Q <= Q + 1;
			else
				if ( Q == 0 )
					Q <= 9;
				else
					Q <= Q - 1;
endmodule
