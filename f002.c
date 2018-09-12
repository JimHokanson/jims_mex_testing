#include "mex.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    //
    //  f002(non_cellstr)
    //
           
    
    const mxArray *cell_array = prhs[0];

    
    char *field_name;
    
    //TODO: Change print statements to be clearer
    
    //This is not a string
    field_name = mxArrayToString(mxGetCell(cell_array,0));
    mexPrintf("f5: %d\n",!field_name);
    mexPrintf("field2: %d\n",field_name);
    mexPrintf("field: %s\n",field_name);
    
    //This doesn't exist. Presumabyl mxGetCell is also returning 0
    field_name = mxArrayToString(mxGetCell(cell_array,1));
    mexPrintf("field3: %d\n",field_name);
    mexPrintf("field4: %s\n",field_name);
    mxFree(field_name);
    
}