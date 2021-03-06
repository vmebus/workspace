//?½å?quantize.m:é«?¯æ??å¯åº¦å½æ¸ç???»é?%
function [r,d]=quantize(L)                //L:?å»ºä?æº??         
r=linspace(0,0,L);
d=linspace(0,0,L+1);
d(1)=0; d(L+1)=500;                       //è¨­å?d0=0ï¼dL =500(ä»?è¡¨ç¡çª®å¤¡±)
d_inc=0.005; r_inc=0.003; error_bound1=0.002; error_bound2=0.003;  
r_estimate=500;tolerance=1e-4;                        
r_init=0.01;                              //r(1)??      
check=0;
while check==0
  r(1)=r_init;                
  for k=1:L-1
    d(k+1)=d(k);                          //?æ¸¬çd(k+1)ä»¥d(k)?å§?ç®          
    //æ¯å°?å¾?r_estimate?r(k)ä¹å·®ï?æ­¤è¿´??¨r(k)çµ¦å?å¾?¾åºd(k+1)// 
    while abs(r_estimate-r(k))>error_bound1       
      d(k+1)=d(k+1)+d_inc;                //é©ç®ä¸ç¬¦å?¥çºå???d_inc
      Int_N=integrate('gau1','x',d(k),d(k+1),tolerance); 
      Int_D=integrate('gau','x',d(k),d(k+1),tolerance); 
      r_estimate=Int_N/Int_D;             
    end
    r(k+1)=2*d(k+1)-r(k);                 //å¾d(k+1)?r(k)æ±r(k+1)
  end                                      
  //å¾?¬å?ç®?ºçrL_estimate?r(k+1)?æ¯è¼// 
  IntL_N=integrate('gau1','x',d(L),d(L+1),tolerance);
  IntL_D=integrate('gau','x',d(L),d(L+1),tolerance); 
  rL_estimate=IntL_N/IntL_D;
  diff=rL_estimate-r(L);
  relative_error=abs(diff)/rL_estimate;                                       
        
   if relative_error<error_bound2
    check=1;
  else
    check=0;
    r_init=r_init+r_inc;                  //ä¸ç¬¦åæ¢ä»¶å??°é¸år(1)
  end        
end  
endfunction;



