module	ADDER4	( A_IN, B_IN, CIN, S, COUT );

input	[3:0]	A_IN, B_IN;
input	CIN;
output	[3:0]	S;
output	COUT;
wire	[2:0]	CY;

	FullAdder	FA0	( A_IN[0], B_IN[0],   CIN, S[0], CY[0] );
  	FullAdder	FA1	( A_IN[1], B_IN[1], CY[0], S[1], CY[1] );
 	FullAdder	FA2	( A_IN[2], B_IN[2], CY[1], S[2], CY[2] );
  	FullAdder	FA3	( A_IN[3], B_IN[3], CY[2], S[3],  COUT );
endmodule