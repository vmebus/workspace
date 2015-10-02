/* SIPO_SHIFT_REG_TEST */
`timescale 1ns/1ns
module	SIPO_SHIFT_REG_TEST;
reg	RESET_B, CLK, IN;
wire [3:0]	Q;
parameter	STEP = 100;

	SIPO_SHIFT_REG	SIPO_SHIFT_REG	(RESET_B, IN, CLK, Q);

	always	#(STEP/2)	CLK = ~CLK;

	initial begin
					RESET_B = 1;	IN = 0;		CLK = 0;
		#(STEP/10) 	RESET_B = 0;
		#(STEP/10)	RESET_B = 1;
		#(STEP/10)					IN = 1;
		#STEP						IN = 0;
		#STEP						IN = 1;
		#STEP						IN = 1;	
		#STEP						IN = 0;
		#STEP		$finish;
	end
endmodule	
