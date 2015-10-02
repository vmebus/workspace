/*	R_SYJKFF	*/
module	R_SYJKFF ( RESET_B, J, K, CLK, Q, Q_B );
input	RESET_B, J, K, CLK;
output	Q, Q_B;
reg	Q;

	assign	Q_B = ~Q;

	always	@( posedge CLK or negedge RESET_B )
		if ( !RESET_B )
			Q <= 0;
		else
			case ( { J, K } )
				1:Q <= 0;
				2:Q <= 1;
				3:Q <= ~Q;
			endcase
endmodule
