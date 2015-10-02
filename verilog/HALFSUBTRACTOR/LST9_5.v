/* HALFSUBTRACTOR_TEST */
`timescale 1ns/1ns
module	HALFSUBTRACTOR_TEST;
reg		A, B;
wire	DIF, BR_OUT;
parameter	STEP = 50;

	HALFSUBTRACTOR	HALFSUBTRACTOR	(A, B, DIF, BR_OUT);

	initial begin
					A = 0;	B = 0;	
	#STEP			A = 1;
	#STEP			A = 0;  B = 1;
	#STEP			A = 1;
	#STEP			A = 0;  B = 0;
	#STEP			$finish;
	end
endmodule	