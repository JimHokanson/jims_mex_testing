function f007_speed_to_initialize_cellstr()

%Does the result depend on the size????
%For strings it can be stored in the header ... so how about 
%char arrays

%   Basically we can't win - nothing speeds up the original by anything
%   meaningful

array_sizes = repmat(int32(5:15),1,1000);

N = 1000;
for j = 1:3
    fprintf('---------\n');
tic
for i = 1:100
data = f007(0,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',0,1000*toc/N);

tic
for i = 1:100
data = f007(1,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',1,1000*toc/N);

tic
for i = 1:100
data = f007(2,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',2,1000*toc/N);

N = 1000;
tic
for i = 1:100
data = f007(3,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',3,1000*toc/N);
end

N = 1000;
for j = 1:3
    fprintf('---------\n');
tic
for i = 1:100
data = f007(0,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',0,1000*toc/N);

tic
for i = 1:100
data = f007(1,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',1,1000*toc/N);

tic
for i = 1:100
data = f007(2,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',2,1000*toc/N);

N = 1000;
tic
for i = 1:100
data = f007(3,array_sizes);
end
fprintf('Option: %d, elapsed time: %0.2f (ms)\n',3,1000*toc/N);
end





end