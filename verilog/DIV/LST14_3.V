/*	ADD_SUB		*/
module	ADD_SUB		( A, B, SUB, S, CY_BR );
input	[4:0]	A, B;
input		SUB;
output	[4:0]	S;
output		CY_BR;
wire	[5:0]	TOTAL;

	assign	TOTAL = FUNC_ADD_SUB ( A, B, SUB );
	assign	S = TOTAL[4:0];
	assign	CY_BR = TOTAL[5];

function	[5:0]	FUNC_ADD_SUB;
input	[4:0]	A, B;
input		SUB;
	if ( SUB )
		FUNC_ADD_SUB = A - B;
	else
		FUNC_ADD_SUB = A + B;
endfunction

endmodule
