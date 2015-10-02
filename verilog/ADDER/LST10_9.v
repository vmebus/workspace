`timescale 1ns/1ns
/* ADDER_TEST */
module ADDER_TEST;
reg		[1:0]	A, B;
wire	[2:0]	ANS;

	ADDER	ADDER	(A, B, ANS);
	
	always	#200	B = B + 1;
	always  #50		A = A + 1;
	
	initial begin
		A = 0;	B = 0;
		#800	$finish;
	end	
endmodule		