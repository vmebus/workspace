//ç¨‹å¼L3_2.m: ?‡?Œ–?€??ˆ?š„?‡è¼ªå?“
X=imread('L3_2.BMP');

Y=X/2;    //B=7;
Z=Y*2;
imshow(Z);

Y=X/16;    //B=4  
W=Y*16;
imshow(W);

imout = imabsdiff(X,W)

