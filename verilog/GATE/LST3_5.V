/* GATE_TEST */
`timescale	1ns/1ns

module	GATE_TEST;
reg		IN_1, IN_2, IN_3;
wire 	OUT_AND, OUT_OR, OUT_NAND, OUT_NOR, OUT_NOT, OUT_BUF, OUT_EXOR;

parameter	STEP = 100;

GATE	GATE	(IN_1, IN_2, IN_3, OUT_AND, OUT_OR, OUT_NAND, OUT_NOR, OUT_NOT, OUT_BUF, OUT_EXOR);

	initial begin
					IN_1 = 0; 	IN_2 = 0;	IN_3 = 0;
		#STEP		IN_1 = 1;
		#STEP		IN_1 = 0;	IN_2 = 1;
		#STEP		IN_1 = 1;
		#STEP		IN_1 = 0;	IN_2 = 0;	IN_3 = 1;
		#STEP		IN_1 = 1;					
		#STEP		IN_1 = 0;	IN_2 = 1;
		#STEP		IN_1 = 1;
		#STEP		$finish;	
	end	
endmodule	