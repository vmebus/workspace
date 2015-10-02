/* MUL_TEST	*/
`timescale	1ns/1ns
module	MUL_TEST;
reg	[3:0]	MD, MQ;
wire [7:0]	ANS;

	MUL MUL	(MD, MQ, ANS);
	
	initial begin
		MD = 4'b1001; MQ = 4'b1011;
		#100	$finish;
	end
endmodule	