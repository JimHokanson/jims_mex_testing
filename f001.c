#include "mex.h"

//  mex f001.c

//        buffer_added: 1
//         json_string: [1×224698929 uint8]
//     allocation_info: [1×1 struct]
//               types: [1×15000005 uint8]
//                  d1: [1×15000005 int32]
//         object_info: [1×1 struct]
//          array_info: [1×1 struct]
//            key_info: [1×1 struct]
//            string_p: [1×1000001 uint64]
//        string_sizes: [1×1000001 int32]
//           numeric_p: [1×4000000 double]
//             strings: {1×1000001 cell}
//         timing_info: [1×1 struct]

int initialized = 0;
mxArray *s2; 

static void clearS2(void)
{
  //mexPrintf("Clearing peristent memory.\n");
  mxDestroyArray(s2);
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    //  Calling Form
    //  ------------
    //  f001(option)
    
    int option = (int)mxGetScalar(prhs[0]);
    
    //1) - DONE Add a field one at a time ...
    //2) - DONE Create with const fieldnames
    //3) - DONE Duplicate already created array
    
    const char *fieldnames[] = {
        "buffer_added","json_string","allocation_info",
        "types", "d1","object_info","array_info","key_info","string_p",
        "string_sizes","numeric_p","strings","timing_info"};
            
    mxArray *s;
    if (option == 1){
        plhs[0] = mxCreateStructMatrix(1,1,0,NULL);
        s = plhs[0];
        mxAddField(s,"buffer_added");
        mxAddField(s,"json_string");
        mxAddField(s,"allocation_info");
        mxAddField(s,"types");
        mxAddField(s,"d1");
        mxAddField(s,"object_info");
        mxAddField(s,"array_info");
        mxAddField(s,"key_info");
        mxAddField(s,"string_p");
        mxAddField(s,"string_sizes");
        mxAddField(s,"numeric_p");
        mxAddField(s,"strings");
        mxAddField(s,"timing_info");
    }else if (option == 2){
        //mxArray *mxCreateStructMatrix(mwSize m, mwSize n, int nfields, const char **fieldnames);
        plhs[0] = mxCreateStructMatrix(1,1,13,fieldnames);
    }else if (option == 3){
        if (!initialized){
            initialized = 1;
            s2 = mxCreateStructMatrix(1,1,13,fieldnames);
            mexMakeArrayPersistent(s2);
            mexAtExit(clearS2);

        }
        plhs[0] = mxDuplicateArray(s2);            
    }else if (option == 4){
        
    }
    
    //setStructField(plhs[0],types,"types",mxUINT8_CLASS,current_data_index + 1);


//     mxArray *pm;    
//     pm = mxCreateNumericArray(0, 0, classid, mxREAL);
//     mxSetData(pm, pr);
//     mxSetM(pm, 1);
//     mxSetN(pm, N);
//     mxAddField(s,fieldname);
//     mxSetField(s,0,fieldname,pm);

}