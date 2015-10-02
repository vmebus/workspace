//L3_4.m: �Q��LBG�V�m�T�Ӥ��P�j�p�P���ת��Xï�ä��O�i��V�q�q��//
loadmatfile('LENA.mat');
th=0.05;
//�V�m�j�p��64���׬�4���Xïcb_64x4//
nc=64;nd=4;
[cb_64x4]=LBG(X,nc,nd,th);
//�V�m�j�p��64���׬�16���Xïcb_64x16//
nc=64;nd=16;
[cb_64x16]=LBG(X,nc,nd,th);
//�V�m�j�p��128���׬�4���Xïcb_128x4//
nc=128;nd=4;
[cb_128x4]=LBG(X,nc,nd,th);

//�ϥ�cb_64x4���Xï�i��V�q�q��//
[M,N]=size(X);
[Y_64x4,bit_64x4]=VQ(X,cb_64x4);      //VQ�禡�b���{���d�Ҥ�
//�p��PSNR�MCR//
MSE=(sum(sum((X-Y_64x4).^2)))/(M*N);
PSNR_64x4=20*log10(255/sqrt(MSE))
CR_64x4=M*N*8/bit_64x4

//�ϥ�cb_64x16���Xï�i��V�q�q��//
[Y_64x16,bit_64x16]=VQ(X,cb_64x16);
MSE=(sum(sum((X-Y_64x16).^2)))/(M*N);
PSNR_64x16=20*log10(255/sqrt(MSE))
CR_64x16=M*N*8/bit_64x16

//�ϥ�cb_128x4���Xï�i��V�q�q��//
[Y_128x16,bit_128x4]=VQ(X,cb_128x4);
MSE=(sum(sum((X-Y_128x16).^2)))/(M*N);
PSNR_128x4=20*log10(255/sqrt(MSE))
CR_128x4=M*N*8/bit_128x4
