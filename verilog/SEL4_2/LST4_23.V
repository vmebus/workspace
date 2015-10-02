/* 4-2 SELECTOR_TEST */
`timescale 1ns/1ns
module SEL4_2_TEST;
reg [1:0] A, B, C, D, SEL_IN;
wire [1:0] OUT;

	SEL4_2	SEL4_2	(A, B, C, D, SEL_IN, OUT);
	
	always	#100 	SEL_IN = SEL_IN + 1;
	always	#40		
		begin	
			A = A + 1;
			B = B + 1;
			C = C + 1;
			D = D + 1;
		end
	
	initial begin
		A = 0; B = 1; C = 2; D = 3;	SEL_IN = 0;
	#700 	$finish;
	end	
endmodule		