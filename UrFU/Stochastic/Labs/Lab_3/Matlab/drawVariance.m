function drawVariance(file_name, Name)

N = importdata('../data/Source/N_set.txt');
V = importdata('../data/V_' + file_name + '.txt');
semilogx(N, V);
title(Name + ' variance')
hold on;
x = [100 N(1,end)];
y = [1 1];
line(x,y,'Color','red','LineStyle','--')
end

