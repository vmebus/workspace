//L3_4.m: 利用LBG訓練三個不同大小與維度的碼簿並分別進行向量量化//
loadmatfile('LENA.mat');
th=0.05;
//訓練大小為64維度為4的碼簿cb_64x4//
nc=64;nd=4;
[cb_64x4]=LBG(X,nc,nd,th);
//訓練大小為64維度為16的碼簿cb_64x16//
nc=64;nd=16;
[cb_64x16]=LBG(X,nc,nd,th);
//訓練大小為128維度為4的碼簿cb_128x4//
nc=128;nd=4;
[cb_128x4]=LBG(X,nc,nd,th);

//使用cb_64x4的碼簿進行向量量化//
[M,N]=size(X);
[Y_64x4,bit_64x4]=VQ(X,cb_64x4);      //VQ函式在本程式範例中
//計算PSNR和CR//
MSE=(sum(sum((X-Y_64x4).^2)))/(M*N);
PSNR_64x4=20*log10(255/sqrt(MSE))
CR_64x4=M*N*8/bit_64x4

//使用cb_64x16的碼簿進行向量量化//
[Y_64x16,bit_64x16]=VQ(X,cb_64x16);
MSE=(sum(sum((X-Y_64x16).^2)))/(M*N);
PSNR_64x16=20*log10(255/sqrt(MSE))
CR_64x16=M*N*8/bit_64x16

//使用cb_128x4的碼簿進行向量量化//
[Y_128x16,bit_128x4]=VQ(X,cb_128x4);
MSE=(sum(sum((X-Y_128x16).^2)))/(M*N);
PSNR_128x4=20*log10(255/sqrt(MSE))
CR_128x4=M*N*8/bit_128x4
