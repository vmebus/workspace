//�禡 VQ.m: �V�q�q��//
function [O_data,bit]=VQ(I_data,I_codebook)
//O_data:�g�V�q�q�����Y���X���//
//I_data:��J���//
//I_codebook:�V�q�q�ƽXï//
//bit:�V�q�q�Ʃһ��`�줸��//
[row,col]=size(I_data);
[nc,nd]=size(I_codebook);
bit_index=ceil(log2(nc));
bit=0;
sqrt_nd=sqrt(nd);
y_ratio=row/sqrt_nd;
x_ratio=col/sqrt_nd;
//�N�C�@�ӦV�q�����Ӱ��V�q�q��//
for i=1:y_ratio
   for j=1:x_ratio
      //���@�Ӽv���϶���@��J���զV�q//
      I_block=I_data((i-1)*sqrt_nd+1:i*sqrt_nd,...
         (j-1)*sqrt_nd+1:j*sqrt_nd);
      //�M��Xï���M����J�V�q�̱��񪺽X�r//
      distortion=sum((((ones(nc,1)*I_block(:)')-I_codebook).^2)')';
      min_distortion=min(find(distortion==min(distortion)));
      //�N���X�r�������N��J�V�q,��@��X�V�q//
      R_block=matrix(I_codebook(min_distortion,:),sqrt_nd,sqrt_nd);
      O_data((i-1)*sqrt_nd+1:i*sqrt_nd,...
         (j-1)*sqrt_nd+1:j*sqrt_nd)=R_block;
      bit=bit+bit_index;                //�֥[�B�z�C�@�ӦV�q���줸��
   end
end
endfunction
