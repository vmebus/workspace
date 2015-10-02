/*  RTFF_TEST */
`timescale	1ns/1ns
module	RTFF_TEST;
reg		R, T;
wire	Q, Q_B;
parameter	STEP =	100;

	RTFF		RTFF	(R, T, Q, Q_B);
	initial begin
					R = 0; 		T = 0;
		#(STEP/5) 	R = 1;
		#(STEP/5)	R = 0;
		#STEP					T = 1;
		#(STEP/2)				T = 0;
		#(STEP*2)				T = 1;
		#STEP					T = 0;
		#STEP		$finish;
	end
endmodule	
		
	