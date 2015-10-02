function a=f2t(S,fs)
N=length(S);
T=1/fs*N;
t=[-(T/2):1/fs:(T/2-1/fs)];
temp1=fft(S)/T;
temp2=N*ifft(S)/T;
a(1:N/2)=temp1(N/2+1:-1:2);
a(N/2+1:N)=temp2(1:N/2);
a=a.*exp((-%i*%pi)*fs*t);
endfunction