/*	ADD4_TEST	*/
`timescale	1ns/1ns
module	ADD4_TEST;
reg			C_IN;
reg	[3:0]	A, B;
wire		C_OUT;
wire [3:0]	SUM;
parameter	STEP = 50;

	ADD4	ADD4	(A, B, C_IN, SUM, C_OUT);

	initial	begin
				A = 4'b0000;	B = 4'b0000; 	C_IN = 1'b0;
	#STEP		A = 4'b0001;
	#STEP		A = 4'b0011;	B = 4'b0001;
	#STEP		A = 4'b0110; 	B = 4'b0011;
	#STEP		A = 4'b1001; 	B = 4'b0110;
	#STEP		A = 4'b1100; 	B = 4'b0011;
	#STEP										C_IN = 1'b1;			
	#STEP		A = 4'b1111; 	B = 4'b0101;
	#STEP					 	B = 4'b1010;	C_IN = 1'b0;
	#STEP		$finish;
	end
endmodule	
		

