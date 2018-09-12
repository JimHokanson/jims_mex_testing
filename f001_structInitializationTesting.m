function f001_structInitializationTesting()
%
%   This code tests different ways of initializing a structure in Matlab.
%
%   1) Create a structure and add fields 1 at a time
%   2) Create a structure with all fields at once
%   3) Create a structure once and use duplicate array functionality
%
%   Example Output - time is for one iteration
%   Option 1: 16.0 us
%   Option 2: 7.8 us
%   Option 3: 6.0 us
%   Option 2: 7.8 us
%   Option 3: 16.0 us

%{
mex f001.c
%}

N = 100000;
tic;
for i = 1:N
data = f001(1);
end
fprintf('Option 1: %0.1f us\n',toc/N*1e6);

tic;
for i = 1:N
data = f001(2);
end
fprintf('Option 2: %0.1f us\n',toc/N*1e6);

tic;
for i = 1:N
data = f001(3);
end
fprintf('Option 3: %0.1f us\n',toc/N*1e6);

tic;
for i = 1:N
data = f001(2);
end
fprintf('Option 2: %0.1f us\n',toc/N*1e6);


N = 100000;
tic;
for i = 1:N
data = f001(1);
end
fprintf('Option 3: %0.1f us\n',toc/N*1e6);


end