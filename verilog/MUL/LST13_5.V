/*	EN_PIN_SOUT_SHIFT	*/
module	EN_PIN_SOUT_SHIFT ( D, SOUT, SIN, EN, LOAD, CLK );
input	[3:0]	D;
input		SIN, EN, LOAD, CLK;
output		SOUT;
reg	[3:0]	SFT_BUF;

	assign 	SOUT = SFT_BUF[0];

	always	@( posedge CLK )
		if ( LOAD )
			SFT_BUF <= D;
		else if ( EN )
			SFT_BUF <= { SIN, SFT_BUF[3:1] };
endmodule
