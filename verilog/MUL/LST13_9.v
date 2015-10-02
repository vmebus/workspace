/* Mul	*/
module	MUL (MD, MQ, ANS);
input	[3:0]	MD, MQ;
output	[7:0]	ANS;

	assign ANS = MD * MQ;
endmodule	
