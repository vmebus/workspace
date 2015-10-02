//?���?�quantize.m:高?���?�?��密度函數的?��?��?��量?��%
function [r,d]=quantize(L)                //L:?��建�?�準?�?         
r=linspace(0,0,L);
d=linspace(0,0,L+1);
d(1)=0; d(L+1)=500;                       //設�?�d0=0，dL =500(�?表無窮夡�)
d_inc=0.005; r_inc=0.003; error_bound1=0.002; error_bound2=0.003;  
r_estimate=500;tolerance=1e-4;                        
r_init=0.01;                              //r(1)?�?      
check=0;
while check==0
  r(1)=r_init;                
  for k=1:L-1
    d(k+1)=d(k);                          //?��測的d(k+1)以d(k)?��始?��算          
    //比對?��得?��r_estimate?��r(k)之差�?�此迴?��?��r(k)給�?�後?��出d(k+1)// 
    while abs(r_estimate-r(k))>error_bound1       
      d(k+1)=d(k+1)+d_inc;                //驗算不符合?��為�?�?�?d_inc
      Int_N=integrate('gau1','x',d(k),d(k+1),tolerance); 
      Int_D=integrate('gau','x',d(k),d(k+1),tolerance); 
      r_estimate=Int_N/Int_D;             
    end
    r(k+1)=2*d(k+1)-r(k);                 //從d(k+1)?��r(k)求r(k+1)
  end                                      
  //從?���?�算?��的rL_estimate?��r(k+1)?��比較// 
  IntL_N=integrate('gau1','x',d(L),d(L+1),tolerance);
  IntL_D=integrate('gau','x',d(L),d(L+1),tolerance); 
  rL_estimate=IntL_N/IntL_D;
  diff=rL_estimate-r(L);
  relative_error=abs(diff)/rL_estimate;                                       
        
   if relative_error<error_bound2
    check=1;
  else
    check=0;
    r_init=r_init+r_inc;                  //不符合條件則?��?��選取r(1)
  end        
end  
endfunction;



