/* ADDER & SUBTRACTOR	*/
module ADD_SUB (A, B, SUB, ANS, CY_BR_OUT);
input  signed [3:0]		A, B;
output signed [3:0]		ANS;
input			SUB;
output			CY_BR_OUT;

	assign {CY_BR_OUT, ANS} = FUNC_ADD_SUB(A,B);
	
function signed [4:0]	FUNC_ADD_SUB;
	input	signed	[3:0]	A, B;
	reg		signed	[4:0]	TOTAL;
	//integer		TOTAL;
	
	begin	
		if (!SUB)	TOTAL = A + B;
		else		TOTAL = A - B;
		
		if (TOTAL < -8)
			begin	
				//TOTAL = TOTAL + 8;
				TOTAL = TOTAL | 5'b01000;
				FUNC_ADD_SUB = {1'b1, TOTAL[3:0]};
			end
		else if (TOTAL > 7)
			begin
				//TOTAL = TOTAL - 8;
				TOTAL = TOTAL & 5'b10111;
				FUNC_ADD_SUB = {1'b1, TOTAL[3:0]};
			end
		else
			FUNC_ADD_SUB = {1'b0, TOTAL[3:0]};
	end
endfunction

endmodule	