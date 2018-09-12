function f002_mxArrayToString_NonString()

% //  Results indicate mxArrayToString basically outputs 0 if 
% //  anything is not kosher.
% //
% //  The second test indicates that mxGetCell is likely doing the same thing.

data = {int8([116   101   115   116   105   110   0])};

f002(data)

f002(data')


end