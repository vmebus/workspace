/* GATE	*/
module GATE	(IN_1, IN_2, IN_3, OUT_AND, OUT_OR, OUT_NAND, OUT_NOR, OUT_NOT, OUT_BUF, OUT_EXOR);
input 	IN_1, IN_2, IN_3;
output	OUT_AND, OUT_OR, OUT_NAND, OUT_NOR, OUT_NOT, OUT_BUF, OUT_EXOR;

	AND_2		AND_2		(IN_1, IN_2, OUT_AND);
	OR_3		OR_3		(IN_1, IN_2, IN_3, OUT_OR);
	NAND_2	NAND_2	(IN_1, IN_2, OUT_NAND);
	NOR_2		NOR_2		(IN_1, IN_2, OUT_NOR);
	NOT_1		NOT_1		(IN_1, OUT_NOT);
	BUF_1		BUF_1		(IN_1, OUT_BUF);
	EXOR_2	EXOR_2	(IN_1, IN_2, OUT_EXOR);
	
endmodule

/* AND_2 */
module	AND_2	(IN1, IN2, OUT);
input		IN1, IN2;
output	OUT;

assign	OUT	= IN1 & IN2;
endmodule

/* OR_3 */
module	OR_3	(IN1, IN2, IN3, OUT);
input		IN1, IN2, IN3;
output	OUT;

assign	OUT	= IN1 | IN2 | IN3;
endmodule

/* NAND_2 */
module	NAND_2	(IN1, IN2, OUT);
input		IN1, IN2;
output	OUT;

assign	OUT	= ~(IN1 & IN2);
endmodule

/* NOR_2 */
module	NOR_2	(IN1, IN2, OUT);
input		IN1, IN2;
output	OUT;

assign	OUT	= ~(IN1 | IN2);
endmodule

/* NOT */
module	NOT_1	(IN, OUT);
input		IN;
output	OUT;

assign	OUT	= ~IN;
endmodule

/* BUF */
module	BUF_1	(IN, OUT);
input		IN;
output	OUT;

assign	OUT	= IN;
endmodule

/* EXOR_2 */
module	EXOR_2	(IN1, IN2, OUT);
input		IN1, IN2;
output	OUT;

assign	OUT	= ~IN1 & IN2 | IN1 & ~IN2;
endmodule
	