//函式energy.m: 能量集中//
function rec_error=energy(image,type,N) //type :轉換方式(DCT or DFT)
//type = 1: DCT，type=2: DFT。//
rec_error=zeros(1,N);
d_image=double(image)/255;              //將原影像的格式轉換為double格式
if type==1                              //作DCT轉換
  coef_all=dct2(d_image);
else
  coef_all=fft2(d_image);               //作DFT轉換
end
for n=1:N
  coef_part=zeros(N,N);
  coef_part(1:n,1:n)=coef_all(1:n,1:n);
    if type==1                          
    rec_image= idct2(coef_part);        //作DCT反轉換
  else                                  
    rec_image=real(ifft2(coef_part));   //作DFT反轉換
  end
  //求誤差量//
  diff=d_image-rec_image;
  rec_error(n)=sum(sum(diff.^2));       //存放誤差量的資料
end
