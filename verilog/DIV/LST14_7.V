/*	SEL5	*/
module	SEL5	( A, B, O, SEL );
input	[4:0]	A, B;
input		SEL;
output	[4:0]	O;

	assign	O = FUNC_SEL5 ( A, B, SEL );

function	[4:0]	FUNC_SEL5;
input	[4:0]	A, B;
input		SEL;
	if ( SEL )
		FUNC_SEL5 = A;
	else
		FUNC_SEL5 = B;
endfunction

endmodule
