/*	SEL12	*/
module	SEL12	( A, B, O, SEL );
input	[11:0]	A, B;
input		SEL;
output	[11:0]	O;

	assign	O = FUNC_SEL12 ( A, B, SEL );

function	[11:0]	FUNC_SEL12;
input	[11:0]	A, B;
input		SEL;
	if ( SEL )
		FUNC_SEL12 = A;
	else
		FUNC_SEL12 = B;
endfunction

endmodule
