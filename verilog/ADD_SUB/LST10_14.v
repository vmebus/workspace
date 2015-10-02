/*	ADD_SUB_TEST */
`timescale	1ns/1ns
module	ADD_SUB_TEST;
reg	signed	[3:0]	A, B;
reg					SUB;
wire signed	[4:0]	ANS;
wire				CY_BR_OUT;
reg					CY_BR_OUT_TEMP;
integer				ANS_TEMP;
integer				h, i, j;

	ADD_SUB		ADD_SUB(A, B, SUB, ANS, CY_BR_OUT);
		
	initial begin
		for (h = 0; h <= 1; h = h + 1)
			begin
			for (i = -8; i <= 7; i = i + 1)
				begin
				for (j = -8; j <= 7; j = j + 1)
					begin
					#19		SUB = h;	B = i;	A = j;
						
					#1 if(!SUB)	ANS_TEMP = A + B;
					else		ANS_TEMP = A - B;
						
					if (ANS_TEMP < -8)
						begin
						ANS_TEMP = ANS_TEMP + 8;
						CY_BR_OUT_TEMP = 1'b1;
						end	
					else if (ANS_TEMP > 7)
						begin
						ANS_TEMP = ANS_TEMP - 8;
						CY_BR_OUT_TEMP = 1'b1;
						end
					else
						CY_BR_OUT_TEMP = 1'b0;
						
					if (!ANS_TEMP[3:0] == ANS)
						begin
						$display("simulation error ANS");
						#10	$finish;
						end
					if (!CY_BR_OUT_TEMP == CY_BR_OUT)	
						begin
						$display("simulation error CY_BR_OUT");
						#10	$finish;
						end  
					end
				end
			end
		#20	$display("successful");
		$finish;
	end
endmodule	
	








							