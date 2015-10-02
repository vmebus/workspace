//�禡energy.m: ��q����//
function rec_error=energy(image,type,N) //type :�ഫ�覡(DCT or DFT)
//type = 1: DCT�Atype=2: DFT�C//
rec_error=zeros(1,N);
d_image=double(image)/255;              //�N��v�����榡�ഫ��double�榡
if type==1                              //�@DCT�ഫ
  coef_all=dct2(d_image);
else
  coef_all=fft2(d_image);               //�@DFT�ഫ
end
for n=1:N
  coef_part=zeros(N,N);
  coef_part(1:n,1:n)=coef_all(1:n,1:n);
    if type==1                          
    rec_image= idct2(coef_part);        //�@DCT���ഫ
  else                                  
    rec_image=real(ifft2(coef_part));   //�@DFT���ഫ
  end
  //�D�~�t�q//
  diff=d_image-rec_image;
  rec_error(n)=sum(sum(diff.^2));       //�s��~�t�q�����
end
