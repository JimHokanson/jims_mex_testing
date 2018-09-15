function f005_structure_c_vs_mx_Testing()

%
%   Takes about 19% of the time to use c struct vs mex
%

N = 1000000;
tic;
for i = 1:N
data = f005(1);
end
fprintf('Option 1: %0.1f us\n',toc/N*1e6);

tic;
for i = 1:N
data = f005(2);
end
fprintf('Option 2: %0.1f us\n',toc/N*1e6);

%Null OP
tic;
for i = 1:N
f005(3);
end
fprintf('Option 2: %0.1f us\n',toc/N*1e6);

end