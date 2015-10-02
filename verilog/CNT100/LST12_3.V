/*	LD_EN_UDCNT10	*/
module	LD_EN_UDCNT10	(  RESET_B, CLK, LOAD, EN, UP, IN, Q, RC );
input	RESET_B, CLK, LOAD, EN, UP;
input	[3:0] IN;
output	[3:0] Q;
output	RC;
reg	[3:0] Q;
	assign	RC = UP & ( Q ==9 ) | ~UP & ( Q == 0 );
	always	@( posedge CLK or negedge RESET_B  )
		if	( !RESET_B )
			Q <= 0;
		else if	( LOAD )
			Q <= IN;
		else if ( EN )
			if ( UP )			// COUNT UP
				if ( Q == 9 )
					Q <= 0;
				else 
					Q <= Q + 1;
			else				// COUNT DOWN
				if ( Q == 0 )
					Q <= 9;
				else 
					Q <= Q - 1;
endmodule
