/* Data Difinition */
`define		SEG_OUT_0		7'b011_1111
`define		SEG_OUT_1		7'b000_0110
`define		SEG_OUT_2		7'b101_1011
`define		SEG_OUT_3		7'b100_1111
`define		SEG_OUT_4		7'b110_0110
`define		SEG_OUT_5		7'b110_1101
`define		SEG_OUT_6		7'b111_1101
`define		SEG_OUT_7		7'b010_0111
`define		SEG_OUT_8		7'b111_1111
`define		SEG_OUT_9		7'b110_1111
`define		SEG_OUT_ERR		7'b111_1001


/*	SEG7 DECODER	*/
module	SEG7_DEC	(IN, OUT);
input	[3:0]	IN;
output	[6:0]	OUT;

	assign OUT = SEG7_DEC_FUNC	(IN);
	
function [6:0] SEG7_DEC_FUNC;
input	[3:0]	IN;
case (IN)
	0: SEG7_DEC_FUNC = `SEG_OUT_0;
	1: SEG7_DEC_FUNC = `SEG_OUT_1;
	2: SEG7_DEC_FUNC = `SEG_OUT_2;
	3: SEG7_DEC_FUNC = `SEG_OUT_3;
	4: SEG7_DEC_FUNC = `SEG_OUT_4;
	5: SEG7_DEC_FUNC = `SEG_OUT_5;
	6: SEG7_DEC_FUNC = `SEG_OUT_6;
	7: SEG7_DEC_FUNC = `SEG_OUT_7;
	8: SEG7_DEC_FUNC = `SEG_OUT_8;
	9: SEG7_DEC_FUNC = `SEG_OUT_9;
	default: SEG7_DEC_FUNC = `SEG_OUT_ERR;
endcase
endfunction
endmodule
	
	








	