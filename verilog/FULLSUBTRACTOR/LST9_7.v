/* 	FULLSUBTRACTOR_TEST	*/
module	FULLSUBTRACTOR_TEST;
reg		A, B, BR_IN;
wire	DIF, BR_OUT;
parameter	STEP = 50;

	FULLSUBTRACTOR	FULLSUBTRACTOR	(A, B, BR_IN, DIF, BR_OUT);
	
	initial begin
				A = 0; B = 0; BR_IN = 0;
		#STEP	A = 1;
		#STEP	A = 0; B = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 0; BR_IN = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 0; BR_IN = 0;
		#STEP   $finish;
	end
endmodule	