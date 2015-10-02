/*	EN_REG13	*/
module	EN_REG13	( D, Q, EN, CLK );
input	[12:0]	D;
input		EN, CLK;
output	[12:0]	Q;
reg	[12:0]	Q;

	always	@( posedge CLK )
		if ( EN )
			Q <= D;
endmodule
