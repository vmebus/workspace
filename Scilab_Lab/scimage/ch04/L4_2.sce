//程式L4_2.m: 影像轉換的能量集中能力//
A=imread('L4_2.bmp');          //讀取原影像  
image1=mat2gray(A);
N=88;                               //處理影像大小
image=image1(1:N,1:N);
error1=energy(image,1,N);           //1指DCT
error2=energy(image,2,N);           //2指DFT
plot(1:N,error1,'-.',1:N,error2)    //虛線是DCT，實線是DFT
xlabel('n(保留n平方的轉換係數) ') 
text(40,80,'DFT')
ylabel('平方誤差')
text(10,20,'DCT')
