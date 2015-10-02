//函式LBG.m: LBG訓練法//
function [I_codebook,O_distortion]=LBG(t_image,nc,nd,th)
//I_codebook:最後所得之碼簿//
//O_distortion:向量到最後所得碼簿之間的平均誤差//
//t_image:訓練資料//
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

//製造初始碼簿//
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
   //步驟 1 : 將碼簿內容當作重心，將所有的向量分類至這些區間//  
   T_dis=0;
   for i=1:1:nt
      P_dis=%inf;
      P_index=0;
      //將每一個向量均歸類到與其距離最短的重心那一類//
      for j=1:1:nc
         dis=((T_image(i,:)-I_codebook(j,:))*(T_image(i,:)-I_codebook(j,:))');
         if dis<P_dis
            P_dis=dis;
            P_index=j; //歸類
         end
      end
      T_dis=T_dis+P_dis/nd;
      id(i)=P_index;
   end
   Dt=[Dt,T_dis/nt];
   //步驟 2 : 重新計算每一個分類區間的重心並取代先前的碼簿內容//
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
   //步驟 3 :計算並判斷向量到其分類重心之間的平均誤差是否小於收斂臨界值th// 
   disp('Distortion of current iteration =');
   disp(T_dis/nt);
   I_count=I_count+1;
   //判斷前一次和這一次的平均誤差的修正量是否小於th//
   if abs((Dt(I_count-1)-Dt(I_count))/Dt(I_count-1))<th
      converge=0;
   end
end
O_distortion= T_dis/nt;        //最後的平均誤差
disp('End of the LBG algorithm');
//endfunction
