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

function a = idct2(arg1,mrows,ncols)
    // IDCT2 2-D inverse discrete cosine transform
    // B = IDCT2(A) returns the two-dimwnsional inverse discrete cosine transform of A.
    
    // B = IDCT2(A, [M N]) or B = IDCT2(A,M,N) pads A with zeros (or truncates A) to create a matrix of size M-by-N before transforming.
    
    // For any A, IDCT2(DCT2(A)) equals A to within roundoff error.
    
    // The discrete cosine transform is often used for image compression applications.
    
    [lhs,rhs]=argn(0);
//    iptchecknargin(1,3,rhs,'Calling file');
    
    [m, n] = size(arg1);
    // Basic algorithm
    if (rhs ==1) then
        if (m >1) & (n > 1) then
            a = idct(idct(arg1).').';
            return;
        else
            mrows = m;
            ncols = n;
        end
    end
    
    // Padding for vector input
    
    b = arg1;
    if rhs==2 then
        ncols = mrows(2);
        mrows = mrows(1);
    end
    
    mpad = mrows;
    npad = ncols;
    if (m ==1 & mpad > m) then
        b(2, 1) = 0;
        m = 2;
    end
    if (n ==1 & npad > n) then
        b(1, 2) = 0;
        n = 2;
    end
    if (m ==1) then
        mpad = npad;
        npad = 1;
    end // For row vector.
    
    // Transform
    
    a = idct(b, mpad);
    if (m > 1 & n > 1) then
        a = idct(a.', npad).';
    end
    
     
endfunction
