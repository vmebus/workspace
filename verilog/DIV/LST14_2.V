/*	DIV	*/
module	DIV	( DD, DQ, ANS, ARE, START, CLOCK, RESET_B );
input	[7:0]	DD;
input	[3:0]	DQ;
input		START, CLOCK, RESET_B;
output	[7:0]	ANS;
output	[3:0]	ARE;
wire		DQ_SEL_IN;
wire		ACC_SEL_IN;
wire		ACC_EN;
wire		JK_FF_K_IN;
wire		JK_FF_Q_OUT, JK_FF_QB_OUT;
wire		ANS_SIN;
wire		ANS_EN;
wire		LAST;
wire	[3:0]	DQ_Q_OUT;
wire	[4:0]	DQ_SEL_A_IN, DQ_SEL_B_IN;
wire	[4:0]	DQ_SEL_OUT;
wire	[4:0]	ADD_SUB_B_IN;
wire	[5:0]	ADD_SUB_OUT;
wire	[11:0]	ACC_SEL_A_IN, ACC_SEL_B_IN;
wire	[12:0]	ACC_D_IN;
wire	[12:0]	ACC_Q_OUT;
wire	[7:0]	ANS_Q_OUT;
wire	[3:0]	CNT16_OUT;

	ADD_SUB			U_ADD_SUB	( ACC_Q_OUT[11:7], ADD_SUB_B_IN, ANS_Q_OUT[0],
							ADD_SUB_OUT[4:0], ADD_SUB_OUT[5] );
	EN_REG4			U_DQ		( DQ, DQ_Q_OUT, START, CLOCK );
	EN_REG13		ACC		( ACC_D_IN, ACC_Q_OUT, ACC_EN, CLOCK );
	EN_SIN_POUT_SHIFT	U_ANS		( ANS_SIN, ANS_Q_OUT, ANS_EN, START, CLOCK );
	R_SYJKFF		JK_FF		( RESET_B, START, JK_FF_K_IN, CLOCK, JK_FF_Q_OUT, JK_FF_QB_OUT );
	EN_CNT16		CNT16		( CNT16_OUT, JK_FF_Q_OUT, CLOCK, START, RESET_B );
	SEL5			DQ_SEL		( DQ_SEL_A_IN, DQ_SEL_B_IN, DQ_SEL_OUT, DQ_SEL_IN );
	SEL12			ACC_SEL		( ACC_SEL_A_IN, ACC_SEL_B_IN, ACC_D_IN[11:0], ACC_SEL_IN );

	assign		DQ_SEL_IN = ~JK_FF_K_IN;
	assign		ACC_SEL_IN = ~START;
	assign		ACC_EN = START | JK_FF_Q_OUT;
	assign		JK_FF_K_IN = CNT16_OUT[3] & ~CNT16_OUT[2] & ~CNT16_OUT[1] & ~CNT16_OUT[0];
	assign		LAST = ~( JK_FF_K_IN & ANS_Q_OUT[0] );
	assign		DQ_SEL_A_IN = { 1'b0, DQ_Q_OUT };
	assign		DQ_SEL_B_IN = { DQ_Q_OUT, 1'b0 };
	assign		ADD_SUB_B_IN = DQ_SEL_OUT & { LAST, LAST, LAST, LAST, LAST };
	assign		ACC_SEL_A_IN = { ADD_SUB_OUT[3:0], ACC_Q_OUT[6:0], 1'b0 };
	assign		ACC_SEL_B_IN = { 4'b0000, DD };
	assign		ACC_D_IN[12] = ADD_SUB_OUT[4];
	assign		ANS = ANS_Q_OUT;
	assign		ANS_SIN = ANS_Q_OUT[0] ^ ADD_SUB_OUT[5];
	assign		ANS_EN = ~JK_FF_K_IN & JK_FF_Q_OUT;
	assign		ARE = ACC_Q_OUT[12:9];

endmodule
