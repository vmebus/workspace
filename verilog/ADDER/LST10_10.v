/* Adder	*/
module	ADDER (A, B, ANS);
input signed [1:0]	A, B;
output	signed [2:0] ANS;

	assign ANS = A + B;
endmodule