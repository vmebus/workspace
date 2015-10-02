/* 	FULLADDER_TEST	*/
module	FULLADDER_TEST;
reg		A, B, CY_IN;
wire	SUM, CY_OUT;
parameter	STEP = 50;

	FULLADDER	FULLADDER	(A, B, CY_IN, SUM, CY_OUT);
	
	initial begin
				A = 0; B = 0; CY_IN = 0;
		#STEP	A = 1;
		#STEP	A = 0; B = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 0; CY_IN = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 1;
		#STEP	A = 1; 
		#STEP	A = 0; B = 0; CY_IN = 0;
		#STEP   $finish;
	end
endmodule	