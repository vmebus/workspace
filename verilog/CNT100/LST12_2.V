/*	CNT100	*/
module	CNT100	(  RESET_B, CLK, LOAD, EN, UP, IN, Q, CNT_99 );
input	RESET_B, CLK, LOAD, EN, UP;
input	[7:0] IN;
output	CNT_99;
output	[7:0] Q;
wire	LOW_CNT_9, HIGH_CNT_9;
	LD_EN_UDCNT10	LOW_CNT	( RESET_B, CLK,LOAD, EN,
					UP, IN[3:0], Q[3:0], LOW_CNT_9 ),
			HIGH_CNT ( RESET_B, CLK, LOAD, EN & LOW_CNT_9 ,
					UP, IN[7:4], Q[7:4], HIGH_CNT_9 );
	assign	CNT_99 = LOW_CNT_9 & HIGH_CNT_9;
endmodule
