exec t2f.sci
exec f2t.sci
//--------------------
fs=64;		//kHz	
T=64;		//ms
tao=1;		//ms; �߽ļe��
A=1;		//�߽Į��T
N=T*fs;
dt=1/fs;
t=[-T/2:dt:T/2-dt];
df=1/T;
f=[-fs/2:df:fs/2-df];

g=zeros(1,N);
idx=find(t>=-tao/2&t<tao/2);
g(idx)=A;

G=t2f(g,fs);

xset("window",0);
plot(f,G);
xlabel("f(kHz)");
title("�x�ί߽Ī��ť߸��ഫ");

Eg=abs(G).^2;
Eg=Eg+%eps;

Egt=(A*tao*sinc(%pi*f*tao)).^2;
Egt=Egt+%eps;

xset("window",1);
plot(f,10*log10(Eg),f,10*log10(Egt),'g');
title("�x�ί߽Ī����/�z�ׯ�q�бK��");
ylabel("Eg(dB)�� /Egt(dB)��");
xlabel("f(kHz)");
mtlb_axis([-10,10,-40,5]);


