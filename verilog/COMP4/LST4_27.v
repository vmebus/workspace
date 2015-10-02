/* 4bit COMPARATER */
module	COMP4	(X, Y, LG_OUT, EQ_OUT, SM_OUT);
input	[3:0] X, Y;
output	LG_OUT, EQ_OUT, SM_OUT;
wire	[2:0]	LG, EQ, SM;

COMP_FULL	COMPFL0	(X[0], Y[0], 1'b0, 1'b1, 1'b0, LG[0], EQ[0], SM[0]),
			COMPFL1	(X[1], Y[1], LG[0], EQ[0], SM[0], LG[1], EQ[1], SM[1]),
			COMPFL2	(X[2], Y[2], LG[1], EQ[1], SM[1], LG[2], EQ[2], SM[2]),
			COMPFL3	(X[3], Y[3], LG[2], EQ[2], SM[2], LG_OUT, EQ_OUT, SM_OUT);
endmodule

/* FULL COMPARATER */
module COMP_FULL		(X, Y, LG_IN, EQ_IN, SM_IN, LG_OUT, EQ_OUT, SM_OUT);
input	X, Y;
input	LG_IN, EQ_IN, SM_IN;
output	LG_OUT, EQ_OUT, SM_OUT;
	assign {LG_OUT, EQ_OUT, SM_OUT} = COMP_FUNC	(X, Y, LG_IN, EQ_IN, SM_IN);

	function [2:0]	COMP_FUNC;
	input X, Y, LG_IN, EQ_IN, SM_IN;
	
	if	(X > Y)
			COMP_FUNC = 3'b100;
	else if (X < Y)
			COMP_FUNC = 3'b001;
	else
		if (LG_IN)
			COMP_FUNC = 3'b100;
		else if (SM_IN)
			COMP_FUNC = 3'b001;
		else
			COMP_FUNC = 3'b010;
	endfunction
endmodule	
			

