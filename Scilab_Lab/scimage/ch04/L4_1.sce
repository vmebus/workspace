//�{��L4_1.sce: SVD�ഫ//
A=[ 1 2 1;2 3 2;1 2 1 ];      //�ŧi�@�ӯx�} A
[u d v]=svd(A);               //�� A �x�}�i�� SVD �ഫ 
[nx,ny]=size(A);              //��X A �x�}���j�p
I=eye(nx,nx);                 //���@�ӳ��x�}�A��j�p��nx��nx
for i=nx:-1:2                
  I(i,i)=0;                   //�N�����쪺�D�﨤�����]�� 0
end      
B=u*I*d*v';                   //�����ĤG�M�ĤT�ӯS�x�ȩ��٭쪺�x�} 
B                             //�N�٭�᪺�x�}��ܥX�� 

//���ڼv���i��SVD�ഫ//
X=imread('L4_1.bmp');  //Ū���v��

A=X(120:219,120:219);         //�N�v�����@�������X�A�éR�W�� A
C=mat2gray(A);
[nx,ny]=size(C);              //��X A �x�}���j�p
I=eye(nx,nx);                 //���@�өM A �P�ˤj�p�����x�} 
for i=nx:-1:21                //�N���x�} I �������D�﨤�u�����]��0
  I(i,i)=0;                   //�H�K�M A ���S�x�ȯx�}�ۭ��� 
end                           //���h�@�������S�x��
[U,S,V]=svd(C);               //�� A �x�}�i�� SVD �ഫ 
B=U*I*S*V';                   //�N A �x�}�٭�^�Өó]�� B
//imshow(C)                 //�N��l���v����ܥX��  
imshow(B)                 //�N����v����ܥX�� 
