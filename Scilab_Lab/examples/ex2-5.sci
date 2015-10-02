exec t2f.sci
exec f2t.sci
exec eyes.sci

N=2^13;
L=16;
M=N/L;
Rs=2;
Ts=1/Rs;
dt=Ts/L;
fs=1/dt;
T=N*dt;
df=1/T;
Bs=N*df/2;

f=[-fs/2+df/2:df:fs/2];
t=[-T/2+dt/2:dt:T/2];

alpha=0.5;
Hcos=zeros(1,N);
ii=find(abs(f)>(1-alpha)/(2*Ts)&abs(f)<=(1+alpha)/(2*Ts));
Hcos(ii)=Ts/2*(1+cos(%pi*Ts/(alpha+%eps)*(abs(f(ii))-(1-alpha)/(2*Ts))));
ii=find(abs(f)<=(1-alpha)/(2*Ts));
Hcos(ii)=Ts;

Hcoss=sqrt(Hcos);
Hcosr=Hcoss;
EP1=zeros(1,N);
EP2=zeros(1,N);
EP3=zeros(1,N);
EP4=zeros(1,N);

for loop1=1:20;
Eb_N0(loop1)=(loop1-1);
eb_n0(loop1)=10^(Eb_N0(loop1)/10);
Eb=1;
n0=Eb/eb_n0(loop1);
sita=n0*Bs;
n_err=0;

for loop2=1:200;
a=sign(rand(1,M,"normal"));
s1=zeros(1,N);

s1(1:L:N)=a/dt;
S1=t2f(s1,fs);
P1=abs(S1).^2/T;
EP1=EP1*(1-1/loop2)+P1/loop2;

S2=S1.*Hcoss;
s2=real(f2t(S2,fs));
P2=abs(S2).^2/T;
EP2=EP2*(1-1/loop2)+P2/loop2;

S=S2.*Hcosr;
y=real(f2t(S,fs));

nw=sqrt(sita)*rand(1,N,"normal");
sr=s2+nw;
SR=t2f(sr,fs);
S3=SR.*Hcosr;
s3=real(f2t(S3,fs));
P3=abs(S3).^2/T;
EP3=EP3*(1-1/loop2)+P3/loop2;

yy=s3(1:L:N);
aa=sign(yy);;
b=zeros(1,N);
b(L/2:L:N)=aa/dt;
B=t2f(b,fs);
P4=abs(B).^2/T;
EP4=EP4*(1-1/loop2)+P4/loop2;
n_err=n_err+length(find(aa~=a));
end

Pe(loop1)=n_err/(M*loop2);
xset("window",11)
plot(Eb_N0,log10(Pe+%eps),'g');
xlabel('Eb_N0');ylabel('Pe');
title("Pe~Eb_N0");
eb_n0=10.^(Eb_N0/10);
set(gca(),"auto_clear","off");
plot(Eb_N0,log10(0.5*erfc(sqrt(eb_n0))));
mtlb_axis([0,15,-3.5,0]);
xlabel('Eb_N0');ylabel('Pe');
legend('實際','理論');
set(gca(),"auto_clear","on");
end

xset("window",1)
plot(t,s1)
title("發送端輸入碼序列波形")
xlabel("t(ms)")
ylabel("s1(t)(V)")
mtlb_axis([-6,+6,min(s1),max(s1)])
xgrid

xset("window",2)
plot(f,EP1)
title("發送端輸入碼序列功率譜")
xlabel("f(kHz)")
ylabel("W/kHz")
mtlb_axis([-6,+6,0,max(EP1)])
xgrid

xset("window",3)
plot(t,s2)
title("發送濾波器輸出波形")
xlabel("t(ms)")
ylabel("s1(t)(V)")
mtlb_axis([-10,+10,-4,+4])
xgrid

xset("window",4)
plot(f,EP2)
title("發送濾波器輸出功率譜")
xlabel("f(kHz)")
ylabel("W/kHz")
mtlb_axis([-2,+2,0,max(EP2)])
xgrid

xset("window",5)
plot(t,sr)
title("接收濾波器輸入波形")
xlabel("t(ms)")
ylabel("s1(t)(V)")
mtlb_axis([-10,+10,-4,+4])
xgrid


xset("window",6)
plot(f,EP3)
title("接收濾波器輸出功率譜")
xlabel("f(kHz)")
ylabel("W/kHz")
mtlb_axis([-2,+2,0,max(EP3)])
xgrid

xset("window",7)
plot(t,b)
title("接收端採樣判決後碼序列波形")
xlabel("t(ms)")
ylabel("b(t)(V)")
mtlb_axis([-6,+6,min(s1),max(s1)])
xgrid

xset("window",8)
plot(f,EP4)
title("接收端採樣判決後碼序列功率譜")
xlabel("f(kHz)")
ylabel("W/kHz")
mtlb_axis([-6,+6,0,max(EP4)])
xgrid

xset("window",9)
title("不加噪聲接收眼圖")
eyes(y,L,3)
xgrid

xset("window",10)
title("加噪聲接收眼圖")
eyes(s3,L,3)
xgrid
