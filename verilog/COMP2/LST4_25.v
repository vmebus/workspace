/* 2bit COMPARATER */
module	COMP2	(X, Y, LG, EQ, SM);
input X, Y;
output LG, EQ, SM;

	assign {LG, EQ, SM} = COMP2_FUNC(X, Y);
	
	function [2:0] COMP2_FUNC;
	input [1:0] X, Y;
	if (X > Y)	
		COMP2_FUNC = 3'b100;
	else if (X < Y)
		COMP2_FUNC = 3'b001;
	else	
		COMP2_FUNC = 3'b010;
	endfunction
endmodule	
	
		