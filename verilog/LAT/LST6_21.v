/* LAT_TEST	*/
`timescale	1ns/1ns
module	LAT_TEST;
reg		D, G;
wire	Q, Q_B;
parameter	STEP = 50;

	LAT	LAT	(D, G, Q, Q_B);
	
	always #(STEP/2)	G = ~G;
	initial	begin
					D = 0;	G = 0;
		#(STEP*5/4)	D = 1;
		#(1.5*STEP)	D = 0;
		#(2*STEP)	D = 1;
		#STEP 		$finish;
	end
endmodule	