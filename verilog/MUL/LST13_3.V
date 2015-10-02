/*	EN_REG4		*/
module	EN_REG4	( D, Q, EN, CLK );
input	[3:0]	D;
input		EN, CLK;
output	[3:0]	Q;
reg	[3:0]	Q;

	always	@( posedge CLK )
		if ( EN )
			Q <= D;
endmodule
