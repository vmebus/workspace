module	FullAdder	( A, B, CY_IN, SUM, CY_OUT );
input	A, B, CY_IN;
output	SUM, CY_OUT;
	assign SUM    = A ^ B ^ CY_IN;
	assign CY_OUT = ( A & B ) | ( A & CY_IN ) | ( B & CY_IN );
endmodule

