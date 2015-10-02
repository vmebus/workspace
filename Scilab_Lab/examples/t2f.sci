function S=t2f(s,fs)
// s代表輸入訊號, S表示s的頻譜, fs是取樣率
N=length(s);
T=1/fs*N;
f=[-N/2:(N/2-1)]/T;
temp1=fft(s)/fs;
temp2=N*ifft(s)/fs;
S(1:N/2)=temp2(N/2+1:-1:2);
S(N/2+1:N)=temp1(1:N/2);
S=S.*exp((%i*%pi)*f*T);
endfunction