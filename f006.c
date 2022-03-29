#include "mex.h"


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    //This will test the fastest way of initializing string data
    
    //Speed of malloc vs mxMalloc???
    
    //  f003(string_lengths)
    
    //1) Current Turtle JSON approach
    //2) Copying allocated strings
    
    int option = (int)mxGetScalar(prhs[0]);

    if (option == 1){
        
        
    }else if (option == 2){
     
        
    }
    
} 