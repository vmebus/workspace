/* 4bit Adder */
module	ADD4	(A, B, C_IN, SUM, C_OUT);
input	C_IN;
input	[3:0]	A, B;
output	C_OUT;
output	[3:0]	SUM;	
wire		[4:0]	TOTAL;

	assign	TOTAL = A + B + C_IN;
	assign	SUM = TOTAL[3:0];
	assign	C_OUT = TOTAL[4];
endmodule
	
