#include "mex.h"
#include <immintrin.h>

//  mex CFLAGS="$CFLAGS -march=native" f008.c
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
    
    int n = mxGetN(prhs[0]);
    
    int z1 = 0;
    int z2 = 0;
    int z3 = 0;
    int z4 = 0;
    int z5 = 0;
    char *data = (char *)mxGetData(prhs[0]);
    char *m = data + n/32;

    __m256i quote = _mm256_set1_epi8 ('"');
    __m256i left_bracket = _mm256_set1_epi8 ('[');
    __m256i right_bracket = _mm256_set1_epi8 (']');
    __m256i left_curly = _mm256_set1_epi8 ('{');
    __m256i right_curly = _mm256_set1_epi8 ('}');
    
    char *i = data;
    for (; i < m; i+=32){
        __m256i temp = _mm256_loadu_si256 ((const __m256i *)i);
        __m256i result1 = _mm256_cmpeq_epi8 (temp,quote);
        __m256i result2 = _mm256_cmpeq_epi8 (temp,left_bracket);
        __m256i result3 = _mm256_cmpeq_epi8 (temp,right_bracket);
        __m256i result4 = _mm256_cmpeq_epi8 (temp,left_curly);
        __m256i result5 = _mm256_cmpeq_epi8 (temp,right_curly);
        z1 += __builtin_popcount(_mm256_movemask_epi8 (result1));  
        z2 += __builtin_popcount(_mm256_movemask_epi8 (result2)); 
        z3 += __builtin_popcount(_mm256_movemask_epi8 (result3));
        z4 += __builtin_popcount(_mm256_movemask_epi8 (result4));
        z5 += __builtin_popcount(_mm256_movemask_epi8 (result5));
    }
    
    //How hard to move selected bytes into memory
    
//     mexPrintf("n chars: %d\n",z1);
//     mexPrintf("n chars: %d\n",z2);
//     mexPrintf("n chars: %d\n",z3);
//     mexPrintf("n chars: %d\n",z4);
//     mexPrintf("n chars: %d\n",z5);
    
} 