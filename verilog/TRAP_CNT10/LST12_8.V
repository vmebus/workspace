/*	TRAP_CNT10	*/
module	TRAP_CNT10	( RESET_B, CLK, TEST, Q );
input	RESET_B, CLK, TEST;
output	[3:0] Q;
reg	[3:0] Q;
wire	[3:0] OUT;
	assign	OUT = { TEST, 3'b000} | INC_OUT ( Q );
	always	@( posedge CLK or negedge RESET_B )
		if ( !RESET_B )
			Q <= 0;
		else
			Q <= OUT;

function	[3:0] INC_OUT;
input	[3:0] Q;
	if ( Q == 9 )
		INC_OUT = 0;
	else
		INC_OUT = Q + 1;
endfunction

endmodule
