/*	SUBTRACTOR4_TEST	*/
`timescale	1ns/1ns
module	SUBTRACTOR4_TEST;
reg [3:0]	A, B;
reg			BR_IN;
wire [3:0]  DIF;
wire		BOUT;
parameter	STEP = 100;

	SUBTRACTOR4	SUBTRACTOR4 (A, B, BR_IN, DIF, BOUT);
	
	initial begin
					A = 0;	B = 0;	BR_IN = 0;
		#STEP		A = 3;
		#STEP		A = 6;
		#STEP		A = 9;
		#STEP						BR_IN = 1;
		#STEP				B = 5;
		#STEP				B = 8; 	BR_IN = 0;
		#STEP				B = 9;
		#STEP		A = 5;
		#STEP		$finish;
	end
endmodule				
			