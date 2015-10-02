//�禡LBG.m: LBG�V�m�k//
function [I_codebook,O_distortion]=LBG(t_image,nc,nd,th)
//I_codebook:�̫�ұo���Xï//
//O_distortion:�V�q��̫�ұo�Xï�����������~�t//
//t_image:�V�m���//
//Rearrangement of the training image//
[row,col]=size(t_image);
nt=row*col/nd;
R_image=[];
sqrt_nd=sqrt(nd);
x_count=fix(col/sqrt_nd);
y_count=fix(row/sqrt_nd);
for i=1:1:y_count
   for j=1:1:x_count
      r_image=t_image((i-1)*sqrt_nd+1:i*sqrt_nd,(j-1)*sqrt_nd+1:j*sqrt_nd);
      R_image=[R_image;r_image(1:nd)];
   end
end
//Read training data and group the data into training vectors//
ratio=fix(y_count*x_count/nt);
T_image=[];
for i=1:ratio:ratio*nt
   T_image=[T_image;i;R_image(1:nd)];
end

//�s�y��l�Xï//
ratio=fix(y_count*x_count/nc);
I_codebook=[];
for i=1:ratio:ratio*nc
   I_codebook=[I_codebook;i;R_image(1:nd)];
end
//LBG Algorithm//
disp('Begin LBG algorithm,and wait........');
Dt=[];
converge=1;
I_count=1;
Dt(1)=%inf;
while(converge)
   //�B�J 1 : �N�Xï���e��@���ߡA�N�Ҧ����V�q�����ܳo�ǰ϶�//  
   T_dis=0;
   for i=1:1:nt
      P_dis=%inf;
      P_index=0;
      //�N�C�@�ӦV�q���k����P��Z���̵u�����ߨ��@��//
      for j=1:1:nc
         dis=((T_image(i,:)-I_codebook(j,:))*(T_image(i,:)-I_codebook(j,:))');
         if dis<P_dis
            P_dis=dis;
            P_index=j; //�k��
         end
      end
      T_dis=T_dis+P_dis/nd;
      id(i)=P_index;
   end
   Dt=[Dt,T_dis/nt];
   //�B�J 2 : ���s�p��C�@�Ӥ����϶������ߨè��N���e���Xï���e//
   for i=1:1:nc
      count=0;
      U_codebook=zeros(1,nd);
      for j=1:1:nt
         if id(j)==i
            U_codebook=U_codebook+T_image(j,:);
            count=count+1;
         end
      end
      if count>0
         I_codebook(i,1:nd)=U_codebook/count;
      end
   end
   //�B�J 3 :�p��çP�_�V�q���������ߤ����������~�t�O�_�p�����{�ɭ�th// 
   disp('Distortion of current iteration =');
   disp(T_dis/nt);
   I_count=I_count+1;
   //�P�_�e�@���M�o�@���������~�t���ץ��q�O�_�p��th//
   if abs((Dt(I_count-1)-Dt(I_count))/Dt(I_count-1))<th
      converge=0;
   end
end
O_distortion= T_dis/nt;        //�̫᪺�����~�t
disp('End of the LBG algorithm');
//endfunction
