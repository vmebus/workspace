/*	SYNC_CNT10_TEST	*/
`timescale 1ns/1ns
module	SYNC_CNT10_TEST;
reg		RESET_B, CLK;
wire	[3:0] Q;
parameter	STEP = 100;

	SYNC_CNT10	SYNC_CNT10	(RESET_B, CLK, Q);
	
	always	#(STEP/2)	CLK = ~CLK;
	initial begin
				RESET_B = 1;	CLK = 0;	
		#(STEP/10)	RESET_B = 0;
		#STEP		RESET_B = 1;
		#(12*STEP)	$finish;
	end
endmodule	
		