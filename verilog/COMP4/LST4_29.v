/* 4bit COMPARATER_TEST */
`timescale 1ns/1ns
module COMP4_TEST;
reg [3:0] X, Y;
wire LG, EQ, SM;

COMP4	COMP4	(X, Y, LG, EQ, SM);

always	#50		X = X + 1;
initial  begin 
		X = 0; Y = 8;
		#800 $finish;
end
endmodule		

