//程式L2_2.m: 矩陣的直積%
A=[1 1;-1 1];
B=[1 2;3 4];
A1=A';   B1=B';             //將矩陣轉置 
A2=inv(A);   B2=inv(B);     //求反矩陣
kron1=kron(A,B);            //求右直接乘積
kron2=kron(A1,B1);
kron3=kron(A2,B2);
kron_left=kron1';
kron_right=kron2;
invert_left=inv(kron1);
invert_right=kron3;
kron_left
kron_right
invert_left
invert_right
y
