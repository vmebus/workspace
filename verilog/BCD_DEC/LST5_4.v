/* Data Difinition */
`define		OUT_0		10'b0000000001
`define		OUT_1		10'b0000000010
`define		OUT_2		10'b0000000100
`define		OUT_3		10'b0000001000
`define		OUT_4		10'b0000010000
`define		OUT_5		10'b0000100000
`define		OUT_6		10'b0001000000
`define		OUT_7		10'b0010000000
`define		OUT_8		10'b0100000000
`define		OUT_9		10'b1000000000
`define		OUT_ERR		10'b0000000000


/*	BCD DECODER	*/
module	BCD_DEC	(IN, OUT, ERR);
input	[3:0]	IN;
output	[9:0]	OUT;
output 	ERR;
	assign {ERR, OUT} = BCD_DEC_FUNC	(IN);
	
function [10:0] BCD_DEC_FUNC;
input	[3:0]	IN;
case (IN)
	0: BCD_DEC_FUNC = {1'b0, `OUT_0};
	1: BCD_DEC_FUNC = {1'b0, `OUT_1};
	2: BCD_DEC_FUNC = {1'b0, `OUT_2};
	3: BCD_DEC_FUNC = {1'b0, `OUT_3};
	4: BCD_DEC_FUNC = {1'b0, `OUT_4};
	5: BCD_DEC_FUNC = {1'b0, `OUT_5};
	6: BCD_DEC_FUNC = {1'b0, `OUT_6};
	7: BCD_DEC_FUNC = {1'b0, `OUT_7};
	8: BCD_DEC_FUNC = {1'b0, `OUT_8};
	9: BCD_DEC_FUNC = {1'b0, `OUT_9};
	default: BCD_DEC_FUNC = {1'b1, `OUT_ERR};
endcase
endfunction
endmodule
	
	








	