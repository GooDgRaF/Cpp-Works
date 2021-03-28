function  drawExpectation(file_name, Name)

N = importdata('../data/Source/N_set.txt');
E = importdata('../data/E_' + file_name + '.txt');
semilogx(N, E);
title(Name + ' expectation')
hold on;
x = [100 N(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
end

