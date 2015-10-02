/* Data Difinition */
`define		SW_IN0		10'b0000000001
`define		SW_IN1		10'b0000000010
`define		SW_IN2		10'b0000000100
`define		SW_IN3		10'b0000001000
`define		SW_IN4		10'b0000010000
`define		SW_IN5		10'b0000100000
`define		SW_IN6		10'b0001000000
`define		SW_IN7		10'b0010000000
`define		SW_IN8		10'b0100000000
`define		SW_IN9		10'b1000000000

/*	BCD ENCODER	*/
module	BCD_ENC	(IN, OUT);
input	[9:0]	IN;
output	[3:0]	OUT;
	assign OUT = BCD_ENC_FUNC	(IN);
	
function [3:0] BCD_ENC_FUNC;
input	[9:0]	IN;
case (IN)
	`SW_IN0: BCD_ENC_FUNC = 0;
	`SW_IN1: BCD_ENC_FUNC = 1;
	`SW_IN2: BCD_ENC_FUNC = 2;
	`SW_IN3: BCD_ENC_FUNC = 3;
	`SW_IN4: BCD_ENC_FUNC = 4;
	`SW_IN5: BCD_ENC_FUNC = 5;
	`SW_IN6: BCD_ENC_FUNC = 6;
	`SW_IN7: BCD_ENC_FUNC = 7;
	`SW_IN8: BCD_ENC_FUNC = 8;
	`SW_IN9: BCD_ENC_FUNC = 9;
	default: BCD_ENC_FUNC = 15;
endcase
endfunction
endmodule
	
	








	