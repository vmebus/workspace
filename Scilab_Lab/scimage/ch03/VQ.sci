//函式 VQ.m: 向量量化//
function [O_data,bit]=VQ(I_data,I_codebook)
//O_data:經向量量化壓縮後輸出資料//
//I_data:輸入資料//
//I_codebook:向量量化碼簿//
//bit:向量量化所需總位元數//
[row,col]=size(I_data);
[nc,nd]=size(I_codebook);
bit_index=ceil(log2(nc));
bit=0;
sqrt_nd=sqrt(nd);
y_ratio=row/sqrt_nd;
x_ratio=col/sqrt_nd;
//將每一個向量均拿來做向量量化//
for i=1:y_ratio
   for j=1:x_ratio
      //取一個影像區塊當作輸入測試向量//
      I_block=I_data((i-1)*sqrt_nd+1:i*sqrt_nd,...
         (j-1)*sqrt_nd+1:j*sqrt_nd);
      //尋找碼簿中和此輸入向量最接近的碼字//
      distortion=sum((((ones(nc,1)*I_block(:)')-I_codebook).^2)')';
      min_distortion=min(find(distortion==min(distortion)));
      //將此碼字直接取代輸入向量,當作輸出向量//
      R_block=matrix(I_codebook(min_distortion,:),sqrt_nd,sqrt_nd);
      O_data((i-1)*sqrt_nd+1:i*sqrt_nd,...
         (j-1)*sqrt_nd+1:j*sqrt_nd)=R_block;
      bit=bit+bit_index;                //累加處理每一個向量的位元數
   end
end
endfunction
