//�{��L3_3.m: �V�q�q�ƾ����Xï������//
//�Q��LBG�k���ͤT�Ӥ��P�j�p�P���ת��Xï//
loadmatfile('LENA.mat'); //Ū�J�@�T 512 X 512 ���v���x�}
th=0.1;                  //�]�wLBG�{������V�m���{�ɭ� 
nc=64;nd=4;              //�]�w�Xï�j�p��64�A���׬�4
[cb_64x4,distortion_64x4]=LBG(X,nc,nd,th);  //LBG�禡�b���{���d�Ҥ�
nc=64;nd=16;
[cb_64x16,distortion_64x16]=LBG(X,nc,nd,th);
nc=128;nd=16;
[cb_128x16,distortion_128x16]=LBG(X,nc,nd,th);
