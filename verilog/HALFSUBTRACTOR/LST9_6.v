/* HALF SUBTRACTOR */
module HALFSUBTRACTOR	(A, B, DIF, BR_OUT);
input 	A, B;
output	DIF, BR_OUT;
wire 	[1:0]	DIFFERENCE;

	assign	DIFFERENCE = A - B;
	assign  DIF = DIFFERENCE[0];
	assign	BR_OUT = DIFFERENCE[1];
endmodule	
