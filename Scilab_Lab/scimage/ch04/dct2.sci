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

function b=dct2(arg1,mrows,ncols)
    
    //DCT2 2-D discrete cosine transform.
    // B = DCT2(A) returns the discrete cosine transform of A.
    // The matrix B is the same size as A and contains the discrete cosine transform coefficients.
    
    // B = DCT2(A,[M N]) or B = DCT2(A,M,N) pads the matrix A with zeros to size M-by-N before transformimg. If M or N is smaller than the corresponding dimension of A, DCT2 truncates A. 
    
    [m, n] = size(arg1);
    // Basic algorithm
    [lhs,rhs]=argn(0);
    
    if (rhs == 1) then
        if (m >1 & n > 1) then
          //  bb=dct(arg1)
            
         //   b=dct(bb.').';
         
            b = dct(dct(arg1).').';
            return;
        else
            mrows = m;
            ncols = n;
        end
    end
    
    // Padding for vector input
    a = arg1;
    if nargin==2 then
        ncols = mrows(2);
        mrows = mrows(1);
    end
    mpad = mrows;
    npad = ncols;
    if (m ==1 & mpad > m) then
        a(2, 1) = 0;
        m = 2;
    end
    if (n == 1 & npad > n) then
        a(1, 2) = 0;
        n = 2;
    end
    if m == 1 then
        mpad = npad;
        npad = 1;
    end // For row vector
    
    // Transform
    
    b = dct(a, mpad);
    if (m > 1 & n > 1) then
        b = dct(b.', npad).';
    end
endfunction
