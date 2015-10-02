/* FULLSUBTRACTOR	*/
module	FULLSUBTRACTOR (A, B, BR_IN, DIF, BR_OUT);
input 	A, B, BR_IN;
output	DIF, BR_OUT;
wire [1:0]	DIFFERENCE;

	assign	DIFFERENCE = A - B - BR_IN;
	assign	DIF = DIFFERENCE[0];
	assign	BR_OUT = DIFFERENCE[1];
endmodule	
