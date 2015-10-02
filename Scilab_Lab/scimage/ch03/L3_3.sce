//程式L3_3.m: 向量量化器之碼簿的產生//
//利用LBG法產生三個不同大小與維度的碼簿//
loadmatfile('LENA.mat'); //讀入一幅 512 X 512 的影像矩陣
th=0.1;                  //設定LBG程式停止訓練的臨界值 
nc=64;nd=4;              //設定碼簿大小為64，維度為4
[cb_64x4,distortion_64x4]=LBG(X,nc,nd,th);  //LBG函式在本程式範例內
nc=64;nd=16;
[cb_64x16,distortion_64x16]=LBG(X,nc,nd,th);
nc=128;nd=16;
[cb_128x16,distortion_128x16]=LBG(X,nc,nd,th);
