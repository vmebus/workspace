/* ADD_SUB_TEST	*/
`timescale 1ns/1ns
module	ADD_SUB_TEST;
reg	[3:0]	A, B;
reg			SUB;
wire [3:0]	ANS;
wire		CY_BR_OUT;

	ADD_SUB		ADD_SUB(A, B, SUB, ANS, CY_BR_OUT);
	initial begin
				A = 4'b0000;	B = 4'b0000;	SUB = 0;	//A=0; B=0 SUB=0
		#100					B = 4'b0001;				//B=1
		#100					B = 4'b0111;				//B=7
		#100	A = 4'b0111;								//A=7
		#100					B = 4'b1111;				//B=-1
		#100					B = 4'b1000;				//B=-8
		#100	A = 4'b1001;					SUB = 1;	//A=-7	SUB=1
		#100					B = 4'b0001;				//B=1
		#100					B = 4'b0111;				//B=7
		#100	A = 4'b0000;								//A=0
		#100					B = 4'b1111;				//B=-1	
		#100					B = 4'b1000;				//B=-8
		#100	$finish;
	end
endmodule	