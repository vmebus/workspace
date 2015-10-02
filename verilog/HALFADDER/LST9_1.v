/* HALFADDER_TEST */
`timescale 1ns/1ns
module	HALFADDER_TEST;
reg		A, B;
wire	SUM, CY_OUT;
parameter	STEP = 50;

	HALFADDER	HALFADDER	(A, B, SUM, CY_OUT);

	initial begin
					A = 0;	B = 0;	
	#STEP			A = 1;
	#STEP			A = 0;  B = 1;
	#STEP			A = 1;
	#STEP			A = 0;  B = 0;
	#STEP			$finish;
	end
endmodule	