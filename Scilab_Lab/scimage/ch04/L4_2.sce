//�{��L4_2.m: �v���ഫ����q������O//
A=imread('L4_2.bmp');          //Ū����v��  
image1=mat2gray(A);
N=88;                               //�B�z�v���j�p
image=image1(1:N,1:N);
error1=energy(image,1,N);           //1��DCT
error2=energy(image,2,N);           //2��DFT
plot(1:N,error1,'-.',1:N,error2)    //��u�ODCT�A��u�ODFT
xlabel('n(�O�dn���誺�ഫ�Y��) ') 
text(40,80,'DFT')
ylabel('����~�t')
text(10,20,'DCT')
