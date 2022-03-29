#include "mex.h"

//  mex f005.c

struct sdata 
{ 
   int buffer_added;
   int alloc__n_tokens_allocated;
   int alloc__n_objects_allocated;
   int alloc__n_arrays_allocated;
   int obj__max_keys_in_object;
   int obj__n_unique_objects;
};

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    //Testing of structure manipulation ...
    //1,2,3
    
    //1 => create matlab structure
    //2 => create c structure
    //3 => print fields from c (for verification)
    
    const char *fieldnames[] = {
        "buffer_added",
        "alloc__n_tokens_allocated",
        "alloc__n_objects_allocated",
        "alloc__n_arrays_allocated",
        "obj__max_keys_in_object",
        "obj__n_unique_objects"};
    
    struct sdata *ptr;
    mxArray *s;
    int *temp_data;
    
    int option = (int)mxGetScalar(prhs[0]);
    
    if (option == 1){
        plhs[0] = mxCreateStructMatrix(1,1,6,fieldnames);
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 1;
        mxSetFieldByNumber(plhs[0],0,0,s);
        
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 2;
        mxSetFieldByNumber(plhs[0],0,1,s);
        
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 3;
        mxSetFieldByNumber(plhs[0],0,2,s);
        
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 4;
        mxSetFieldByNumber(plhs[0],0,3,s);
        
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 5;
        mxSetFieldByNumber(plhs[0],0,4,s);
        
        s = mxCreateNumericMatrix(1, 1, mxINT32_CLASS, 0);
        temp_data = (int *)mxGetData(s);
        *temp_data = 6;
        mxSetFieldByNumber(plhs[0],0,5,s);

               
    }else if(option == 2){
        ptr = (struct sdata*)mxMalloc(sizeof(struct sdata));
        ptr->buffer_added = 1;
        ptr->alloc__n_tokens_allocated = 2;
        ptr->alloc__n_objects_allocated = 3;
        ptr->alloc__n_arrays_allocated = 4;
        ptr->obj__max_keys_in_object = 5;
        ptr->obj__n_unique_objects = 6;
        plhs[0] = mxCreateNumericMatrix(0, 1, mxUINT8_CLASS, 0);
        mxSetData(plhs[0],ptr);
        mxSetM(plhs[0],sizeof(struct sdata));
    }else if(option == 3){
        //Do nothing ...

    }
    
}