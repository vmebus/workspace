/* BCD ADDER */
module BCD_ADDER	(A, B, C_IN, BCD_SUM, BCD_COUT);
input	[3:0]	A, B;
input			C_IN;
output	[3:0]BCD_SUM;
output	BCD_COUT;
wire [4:0]	ADDER0_OUT;

	assign	ADDER0_OUT = FUNC_BCD_ADDER (A, B, C_IN);
	assign	BCD_SUM = ADDER0_OUT[3:0];
	assign	BCD_COUT = ADDER0_OUT[4];
	
	function [4:0] FUNC_BCD_ADDER;
		input 	[3:0]	A, B;
		input	C_IN;
		integer	ADDER0_S;
		
		begin	ADDER0_S = A + B +C_IN;
					if (ADDER0_S >= 10) ADDER0_S = ADDER0_S + 6;
				FUNC_BCD_ADDER = ADDER0_S;
		end
	endfunction
endmodule	