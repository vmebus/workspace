/*	EN_SIN_POUT_SHIFT	*/
module	EN_SIN_POUT_SHIFT	( SIN, Q, EN, PS, CLK );
input		SIN;
input		EN, PS, CLK;
output	[7:0]	Q;
reg	[7:0]	Q;

	always	@( posedge CLK )
		if ( PS )
			Q[0] <= 1;
		else if ( EN )
			Q <= { Q[6:0], SIN };
endmodule
