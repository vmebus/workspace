/*	BCD_ADDER_TEST	*/
module	BCD_ADDER_TEST;
reg	[3:0]	A, B;
reg			C_IN;
wire [3:0]	BCD_SUM;
wire		BCD_COUT;
parameter	STEP = 50;

	BCD_ADDER	BCD_ADDER	(A, B, C_IN, BCD_SUM, BCD_COUT);
	
	initial begin
					A = 0;	B = 0; 	C_IN = 0;
		#STEP		A = 3;
		#STEP		A = 6;
		#STEP		A = 9;
		#STEP						C_IN = 1;
		#STEP				B = 5;
		#STEP				B = 8; 	C_IN = 0;
		#STEP				B = 9;
		#STEP		A = 5;
		#STEP		$finish;
	end
endmodule	


