/* RS Flip-Flop */
module	RSFF	(R, S, Q, Q_B);
input	R, S;
output	Q, Q_B;
reg		Q, Q_B;
	always	@ ( R or S)
		case ({R,S})
			1: begin Q <= 1; Q_B <= 0; end
			2: begin Q <= 0; Q_B <= 1; end
			3: begin Q <= 0; Q_B <= 0; end
		endcase
endmodule		
			