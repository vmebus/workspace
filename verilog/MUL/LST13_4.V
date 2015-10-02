/*	EN_REG9		*/
module	EN_REG9	( D, Q, EN, CLR, CLK );
input	[8:0]	D;
input		EN, CLR, CLK;
output	[8:0]	Q;
reg	[8:0]	Q;

	always	@( posedge CLK )
		if ( CLR )
			Q <= 0;
		else if ( EN )
			Q <= D;
endmodule
