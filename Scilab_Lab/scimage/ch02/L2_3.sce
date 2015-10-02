//程式L2_3.m: 馬可夫鏈的轉移機率%
k=8;
l=1;
P(1:2,1:2,1)=[0.75 0.25;0.50 0.50];      //設定機率矩陣(即初始狀態機率)
Q=size(P);
Q=Q(2);

for kk=2:k
  for i=1:Q
    for j=1:Q
      P(j,i,kk)=0;
      for q=1:Q 
        P(j,i,kk)=P(j,i,kk)+P(j,q,l)*P(q,i,kk-l);
      end
    end
  end 
end 
