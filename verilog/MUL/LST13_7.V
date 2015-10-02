/*	EN_CNT8		*/
module	EN_CNT8 ( Q, EN, CLK, CLR_SY, CLR_USY );
input		EN, CLK, CLR_SY, CLR_USY;
output	[2:0]	Q;
reg	[2:0]	Q;
	always	@( posedge CLK or negedge CLR_USY )
		if ( !CLR_USY )
			Q <= 0;
		else if ( CLR_SY ) 
			Q <= 0;
		else if ( EN )
			Q <= Q + 1;
endmodule
