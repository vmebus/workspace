exec t2f.sci
exec f2t.sci

fm=1;		//單位 kHz
fc=20;		//單位 kHz

fs=100;		//kHz
T=100;		//ms
N=T*fs;
dt=1/fs;
t=[-T/2:dt:T/2-dt];
df=1/T;
f=[-fs/2:df:fs/2-df];	

m=cos((2*%pi)*fm*t);
xset("window",0);
plot(t,m);
mtlb_axis([0,2,-1.5,1.5]);

M=t2f(m,fs);	
xset("window",1);
plot(f,M);
mtlb_axis([-50,50,0,120]);


MH=-%i*sign(f).*M;	//在頻域上進行希爾伯特變換
mh=real(f2t(MH,fs));	//希爾伯特變換後的訊號

s=m.*cos((2*%pi)*fc*t)-mh.*sin((2*%pi)*fc*t);	//上邊帶SSB訊號
xset("window",3);
plot(t,s);
mtlb_axis([0,2,-1.5,1.5]);


S=t2f(s,fs);
xset("window",4);
plot(f,S);
mtlb_axis([-50,50,0,120]);
