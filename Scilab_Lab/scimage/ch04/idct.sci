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

function a = idct(b,n)
    
    [lhs,rhs]=argn(0);
    if rhs==0 then
        error('Wrong number of input arguments.');
    end
    if isempty(b) then
        a = [];
        return
   end
    
    //If input is a vector, make it a column:
    do_trans = (size(b,1) == 1);
    if do_trans then
        b = b(:);
    end
    if rhs==1 then
        n = size(b,1);
    end
    m = size(b,2);
    
    // Check the input data type. Single precision is not supported.
    try
        chkinputdatatype(b,n);
    catch
        disp("exception 1");
    end
    
    // Pad or truncate b if necessary
    if size(b,1)<n then
        bb = zeros(n,m);
        bb(1:size(b,1),:) = b;
    else
        bb = b(1:n,:);
    end
    // Compute weights
    ww = sqrt(2*n) * exp(1*%i*(0:n-1)*%pi/(2*n)).';
    
    if modulo(n,2) ==1 | ~isreal(b) then //odd case
        // From intermediate even-symmetric matrix
        ww(1) = ww(1) * sqrt(2);
        W = ww(:,ones(1,m));
        yy = zeros(2*n,m);
        yy(1:n,:) = W.*bb;
        yy(n+2:2*n,:) = (-1*%i)*W(2:n,:).*(bb($:-1:2,:));
        
        y = mtlb_ifft(yy);
        
        // Extract inverse DCT
        a = y(1:n,:);
        
    else // even case
        // Compute precorrection factor
        ww(1) = ww(1)/sqrt(2);
        W = ww(:,ones(1,m));
        yy = W.*bb;
        
        // Compute x tilde using equation (5.93) in Jain
        y = mtlb_ifft(yy);
        
        // Re-order elements of each column according to equation (5.93) and 
        // (5.94) in Jain
        a = zeros(n,m);
        a(1:2:n,:) = y(1:n/2,:);
        a(2:2:n,:) = y(n:-1:n/2+1,:);
    end
    
    if isreal(b) then
        a = real(a);
    end
    if do_trans then
        a = a.';
    end
    
endfunction
