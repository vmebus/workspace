/* Full Adder */
module FULLADDER	(A, B, CY_IN, SUM, CY_OUT);
input	A, B, CY_IN;
output	SUM, CY_OUT;
wire	[1:0]	TOTAL;
	assign TOTAL = A + B + CY_IN;
	assign SUM = TOTAL [0];
	assign CY_OUT = TOTAL [1];
endmodule	
	
