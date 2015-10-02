/* SUBTRACTOR4 */
module	SUBTRACTOR4	(A, B, BR_IN, DIF, BOUT);
input	[3:0]	A, B;
input	BR_IN;
output	[3:0]	DIF;
output	BOUT;
wire	[3:0]	BR;

	FULLSUBTRACTOR	FS0 (A[0], B[0], BR_IN, DIF[0], BR[0]),
					FS1 (A[1], B[1], BR[0], DIF[1], BR[1]),
					FS2 (A[2], B[2], BR[1], DIF[2], BR[2]),
					FS3 (A[3], B[3], BR[2], DIF[3], BOUT);
endmodule					
					
