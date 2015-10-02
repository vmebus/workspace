/* EVEN PARITY GENERATOR*/
module EVEN_PARITY (IN, ODD_OUT);
input [3:0] IN;
output ODD_OUT;
	assign ODD_OUT = ^(IN);
endmodule
