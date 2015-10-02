/* 2bit COMPARATER_TEST */
`timescale 1ns/1ns
module COMP2_TEST;
reg [1:0] X, Y;
wire LG, EQ, SM;

	COMP2	COMP2	(X, Y, LG, EQ, SM);
	
	always	#40			X = X + 1;
	always	#160		Y = Y + 1;
			
	initial begin
				X = 0;
				Y = 0;
		#800	$finish;
	end
endmodule	