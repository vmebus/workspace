//////////////////////////////////////////////////////////////////////////// 
// Image_Processing_toolbox_2
//
// Copyright (c) by S. Parua Biswas, CDAC, Kolkata.  2013
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
////////////////////////////////////////////////////////////////////////////

function b=dct(a,n)
    [lhs,rhs]=argn(0);
    if rhs==0 then
        error('Wrong number of input arguments.');
    end
    if isempty(a) then
        b = [];
        return
    end
//  if n == -1 then  
        
    //If input is a vector, make it a column:
    do_trans = (size(a,1) == 1);
    if do_trans then
        a = a(:);
    end
    
    if rhs==1 then
        n = size(a,1);
    end
    m = size(a,2);
  
    //Pad or truncate input if necessary
    if size(a,1)<n then
        aa = zeros(n,m);
        aa(1:size(a,1),:) = a;
    else
        aa = a(1:n,:);
    end
    // Compute weights to multiply DFT coefficients
    ww = (exp(-1*%i*(0:n-1)*%pi/(2*n))/sqrt(2*n)).';
  
    ww(1) = ww(1) / sqrt(2);
  
        
    if modulo(n,2)==1  | ~isreal(a) then // odd case
        // Form intermediate even-symmetric matrix
        y = zeros(2*n,m);
        y(1:n,:) = aa;
        y(n+1:2*n,:) = aa($:-1:1,:);
        
        // Compute the FFT and keep the appropriate portion:
        yy = mtlb_fft(y);
        yy=yy(1:n,:);
        
        
    else // even case
        // Re-order the elements of the columns of x
        y = [aa(1:2:n,:); aa(n:-2:2,:) ];
        yy = mtlb_fft(y);
        
        ww = 2*ww; // Double the weights for even-length case
        // disp('else')
    end
    
    
    // Multiple FFT by weights:
    b = ww(:,ones(1,m)) .* yy;
    // disp(b)
    if isreal(a) then
        b = real(b);
    end
    if do_trans then
        b = b.';
    end
 
           
endfunction
