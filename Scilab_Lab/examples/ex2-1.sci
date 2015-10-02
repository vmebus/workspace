exec t2f.sci
exec f2t.sci
//--------------------
N=2^12;
fs=16;
Bs=fs/2;
T=N/fs;
t=-T/2+[0:N-1]/fs;
f=-Bs+[0:N-1]/T;
f0=1; A=2; phi=%pi/3;
//�H�W�O��l�ưѼƳ]�w

s=A*cos((2*%pi)*f0*t+phi);
S=t2f(s,fs);
ss=real(f2t(S,fs));
//�H�W�O����������

xset("window",1);
plot(t,s,t,ss,"^")
title("��l�T���H�Τ��ഫ�᪺�T���i��")
xlabel("t(ms)")
ylabel("s(t)(V)")
mtlb_axis([0,3,-2.5,+2.5])

xset("window",2);
plot(f,abs(S))
title("��l�T�����W�й�")
xlabel("f(kHz)")
ylabel("|S(f)|(V/Hz)")
