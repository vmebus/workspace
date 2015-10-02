/*	EN_REG4	*/
module	EN_REG4	( CLR_B, D, CLK, EN, Q );
input	CLR_B, CLK, EN;
input	[3:0] D;
output	[3:0] Q;
reg	[3:0] Q;
	always	@( posedge CLK or negedge CLR_B  )
		if ( !CLR_B )
			Q <= 0;
		else if ( EN )
			Q <= D;
endmodule
