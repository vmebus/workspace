/* 4-2 SELECTOR */
module SEL4_2 (A, B, C, D, SEL, OUT);
input [1:0] A, B, C, D, SEL;
output [1:0] OUT;

	assign OUT = SEL4_2_FUNC (A, B, C, D, SEL);

function [1:0] SEL4_2_FUNC;
input [1:0] A, B, C, D;
input [1:0] SEL;

		case (SEL)
			0: SEL4_2_FUNC = A;
			1: SEL4_2_FUNC = B;
			2: SEL4_2_FUNC = C;
			4: SEL4_2_FUNC = D;	
		endcase
endfunction
	
endmodule
	