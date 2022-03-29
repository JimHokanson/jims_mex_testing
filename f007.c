#include "mex.h"

//  mex f007.c
//
//


void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray*prhs[])
{
    //This will test the fastest way of initializing string data
    
    //Speed of malloc vs mxMalloc???
    
    //  f003(string_lengths)
    
    //0) Current Turtle JSON approach
    //1) Unitialized data
    //2) duplicate header, new data
    //3) copy entire mxArray (header and data)
    
    int option = (int)mxGetScalar(prhs[0]);
    int *sizes = (int *)mxGetData(prhs[1]);
    int n_entries = mxGetN(prhs[1]);

    
    //Variables
    //int n_entries
    //sizes array
    
    int n_chars_max_in_string;
    mxArray *cell_array = mxCreateCellMatrix(1,n_entries);
    mxArray *temp_mx_array;
    uint16_t *cell_data;
    uint16_t **all_cells_data = mxMalloc(n_entries*sizeof(cell_data));
    
    if (option == 0){
        for (int i = 0; i < n_entries; i++){
            n_chars_max_in_string = sizes[i];

            //String initialization
            //--------------------------------------
            //mxCreateUninitNumericMatrix is an option but it is
            //relatively new so we'll avoid it(2015a or newer :/)
            temp_mx_array = mxCreateNumericMatrix(1,0,mxCHAR_CLASS,mxREAL);
            cell_data = mxMalloc(n_chars_max_in_string*2);
            //This approach avoids initialization of the data
            mxSetData(temp_mx_array,cell_data);
            mxSetN(temp_mx_array,n_chars_max_in_string);

            //Hold onto for populating the actual data (next loop)
            all_cells_data[i] = cell_data;

            //Put the string in the cell array
            mxSetCell(cell_array,i,temp_mx_array); 
        }
    }else if (option == 1){
        for (int i = 0; i < n_entries; i++){
            n_chars_max_in_string = sizes[i];
            
            temp_mx_array = mxCreateUninitNumericMatrix(1,n_chars_max_in_string,mxCHAR_CLASS,mxREAL);
            
            all_cells_data[i] = mxGetData(temp_mx_array);
            
            mxSetCell(cell_array,i,temp_mx_array); 
        }
    }else if (option == 2){
        mxArray *temp_mx_array2 = mxCreateNumericMatrix(1,0,mxCHAR_CLASS,mxREAL);
        for (int i = 0; i < n_entries; i++){
            n_chars_max_in_string = sizes[i];

            //String initialization
            //--------------------------------------
            //mxCreateUninitNumericMatrix is an option but it is
            //relatively new so we'll avoid it(2015a or newer :/)
            temp_mx_array = mxDuplicateArray(temp_mx_array2);
            cell_data = mxMalloc(n_chars_max_in_string*2);
            //This approach avoids initialization of the data
            mxSetData(temp_mx_array,cell_data);
            mxSetN(temp_mx_array,n_chars_max_in_string);

            //Hold onto for populating the actual data (next loop)
            all_cells_data[i] = cell_data;

            //Put the string in the cell array
            mxSetCell(cell_array,i,temp_mx_array); 
        }    
    }else if (option == 3){
        //This is probably as fast as we could ever go ...
        mxArray *temp_mx_array2 = mxCreateUninitNumericMatrix(1,15,mxCHAR_CLASS,mxREAL);
        for (int i = 0; i < n_entries; i++){
            n_chars_max_in_string = sizes[i];

            //String initialization
            //--------------------------------------
            //mxCreateUninitNumericMatrix is an option but it is
            //relatively new so we'll avoid it(2015a or newer :/)
            temp_mx_array = mxDuplicateArray(temp_mx_array2);
            all_cells_data[i] = mxGetData(temp_mx_array);

            //Put the string in the cell array
            mxSetCell(cell_array,i,temp_mx_array); 
        }    
    }
    
    plhs[0] = cell_array;
    
    //mxDestroyArray(cell_array);
    
} 






