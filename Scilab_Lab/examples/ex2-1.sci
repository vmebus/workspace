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
//以上是初始化參數設定

s=A*cos((2*%pi)*f0*t+phi);
S=t2f(s,fs);
ss=real(f2t(S,fs));
//以上是模擬的部分

xset("window",1);
plot(t,s,t,ss,"^")
title("原始訊號以及反轉換後的訊號波形")
xlabel("t(ms)")
ylabel("s(t)(V)")
mtlb_axis([0,3,-2.5,+2.5])

xset("window",2);
plot(f,abs(S))
title("原始訊號的頻譜圖")
xlabel("f(kHz)")
ylabel("|S(f)|(V/Hz)")
