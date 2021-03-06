/*	MUL	*/
module	MUL	( MD, MQ, ANS, START, CLOCK, RESET_B );
input	[3:0]	MD, MQ;
input		START, CLOCK, RESET_B;
output	[7:0]	ANS;
wire		MQ_S_OUT;
wire		JK_FF_K_IN;
wire		JK_FF_Q_OUT, JK_FF_QB_OUT;
wire	[3:0]	MD_Q_OUT;
wire	[3:0]	ADDER4_A_IN;
wire	[4:0]	ADDER4_OUT;
wire	[2:0]	CNT8_OUT;
wire	[8:0]	ACC_D_IN;
wire	[8:0]	ACC_Q_OUT;

	EN_REG4			U_MD		( MD, MD_Q_OUT, START, CLOCK );
	ADDER4			U_ADDER4 	( ADDER4_A_IN, ACC_Q_OUT[8:5], 1'b0,
							ADDER4_OUT[3:0], ADDER4_OUT[4] );
	EN_REG9			ACC		( ACC_D_IN, ACC_Q_OUT, JK_FF_Q_OUT, START, CLOCK );
	EN_PIN_SOUT_SHIFT	U_MQ		( MQ, MQ_S_OUT, 1'b0, JK_FF_Q_OUT, START, CLOCK );
	R_SYJKFF		JK_FF		( RESET_B, START, JK_FF_K_IN, CLOCK, JK_FF_Q_OUT, JK_FF_QB_OUT );
	EN_CNT8			CNT8		( CNT8_OUT, JK_FF_Q_OUT, CLOCK, START, RESET_B );

	assign		ADDER4_A_IN = MD_Q_OUT & { MQ_S_OUT, MQ_S_OUT, MQ_S_OUT, MQ_S_OUT };
	assign		ACC_D_IN = { ADDER4_OUT, ACC_Q_OUT[4:1] };
	assign		JK_FF_K_IN = CNT8_OUT[2] & ~CNT8_OUT[1] & ~CNT8_OUT[0];
	assign		ANS = ACC_Q_OUT[7:0];
endmodule
