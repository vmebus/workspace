/*	PISO_SHIFT_REG_TEST	*/
module	PISO_SHIFT_REG_TEST;
reg	LOAD, CLK;
reg 	[3:0]	IN;
wire	[3:0]	Q;
parameter	STEP = 100;

	PISO_SHIFT_REG	PISO_SHIFT_REG	(LOAD, IN, CLK, Q);
	always #(STEP/2)	CLK  = ~CLK;
	initial	begin
					LOAD = 0; IN = 11;	CLK = 0;
		#(STEP/10)	LOAD = 1;
		#(STEP/10)	LOAD = 0;
		#(STEP*5)	$finish;
	end
endmodule	
