#include "mex.h"
#include <immintrin.h>

//  mex CFLAGS="$CFLAGS -march=native" f009.c
//
//

/*
data = ones(1,1e9,'uint8');
data(1:20:end) = uint8('"');
data(2:40:end) = uint8('[');
data(3:60:end) = uint8(']');
data(4:80:end) = uint8('{');
data(5:100:end) = uint8('}');

tic
f008(data);
toc
 
tic
length(strfind(data,uint8('"')));
toc
 */

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{

    
    //  f008(byte_string)
    
    //0) Current Turtle JSON approach
    //1) Unitialized data
    //2) duplicate header, new data
    //3) copy entire mxArray (header and data)
    
    int z1;
    
    __m256i quote = _mm256_set1_epi8 ('"');
    
    char i[100] = "This \" test I think asdfasdf aasdfasdfsadfasdfasdfsadfsdf asdfasdf sadf asf sdfsf asfasdf";

        __m256i temp = _mm256_loadu_si256 ((const __m256i *)i);
        __m256i result1 = _mm256_cmpeq_epi8 (temp,quote);
        z1 = _mm256_movemask_epi8 (result1);
        
        
    mexPrintf("n chars: %d\n",z1); 
    
    //How hard to move selected bytes into memory
    
//     mexPrintf("n chars: %d\n",z1);
//     mexPrintf("n chars: %d\n",z2);
//     mexPrintf("n chars: %d\n",z3);
//     mexPrintf("n chars: %d\n",z4);
//     mexPrintf("n chars: %d\n",z5);
    
} 