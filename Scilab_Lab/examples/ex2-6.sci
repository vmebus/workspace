exec t2f.sci
exec f2t.sci

L=32;
N=2^13;
M=N/L;
Rb=2;
Ts=1/Rb;
fs=L/Ts;
T=N/fs;
Bs=fs/2;
t=-T/2+[0:N-1]/fs;
f=-Bs+[0:N-1]/T;

EP1=zeros(1,N);
EP2=zeros(1,N);
EP3=zeros(1,N);
EP4=zeros(1,N);
EP5=zeros(1,N);
EP6=zeros(1,N);
EP7=zeros(1,N);
EP8=zeros(1,N);

for loop=1:1000
	tmp1=zeros(L,M);
	tmp2=zeros(L,M);
	tmp3=zeros(L,M);
	tmp4=zeros(L,M);
	tmp5=zeros(L,M);
	tmp6=zeros(L,M);
	tmp7=zeros(L,M);
	tmp8=zeros(L,M);
	
	a=(rand(1,M)>0.5)+0;
	b=sign(a-0.5);
	
	L1=L*0.25;
	
	tmp1([1:L1],:)=ones(L1,1)*a;
	s1=tmp1(:)';
	S1=t2f(s1,fs);
	P1=abs(S1).^2/T;
	EP1=EP1*(1-1/loop)+P1/loop;
	
	tmp2([1:L1],:)=ones(L1,1)*b;
	s2=tmp2(:)';
	S2=t2f(s2,fs);
	P2=abs(S2).^2/T;
	EP2=EP2*(1-1/loop)+P2/loop;
	
end	

xset("window",0)
plot(t,s1);
mtlb_axis([-6,+6,-1.5,1.5]);

xset("window",1)
plot(f,10*log(EP1+%eps));

xset("window",2)
plot(t,s2);
mtlb_axis([-6,+6,-1.5,1.5]);

xset("window",3)
plot(f,10*log(EP2+%eps));