/* Half Adder	*/
module	HALFADDER	(A, B, SUM, CY_OUT);
input	A, B;
output	SUM, CY_OUT;

	assign SUM = A ^ B;
	assign CY_OUT = A & B;
endmodule	
