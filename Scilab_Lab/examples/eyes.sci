function eyes(result,L,Na)
N=length(result);
tt=0:1:Na*L;
set(gca(),"auto_clear","off");
for jj=1:Na*L:N-Na*L
    plot(tt,result(jj:jj+Na*L));
    end
set(gca(),"auto_clear","on");
endfunction