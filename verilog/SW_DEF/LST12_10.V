/*	SW_DEF	*/
module	SW_DEF	( RESET_B, CLK, SW_INPUT, Q );
input	RESET_B, CLK, SW_INPUT;
output	[3:0] Q;
reg	QA, QB;
wire	ALFA, BETA;

	always	@( posedge CLK or negedge RESET_B  )
		if	( !RESET_B )
			begin
				QA <= 0;
				QB <= 0;
			end
		else
			begin
				QA <= SW_INPUT;
				QB <= QA;
			end

	assign	ALFA  = ~QB &  QA;
	assign	BETA  =  QB & ~QA;

	EN_CNT10	EN_CNT10    ( RESET_B, CLK, ALFA | BETA, Q );
endmodule
