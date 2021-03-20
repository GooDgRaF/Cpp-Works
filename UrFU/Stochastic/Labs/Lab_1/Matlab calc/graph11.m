clc
clear
close
E = importdata('../data/E.txt');
E_Mer = importdata('../data/E_Mer.txt');
V = importdata('../data/V.txt');
V_Mer = importdata('../data/V_mer.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Amount of data')
%hold on;

%Матожидание
nexttile
semilogx(E(1,:),E(2,:));
title('Expectation')
x = [1 E(1,end)];
y = [0.5 0.5];
line(x,y,'Color','red','LineStyle','--')

%Матожидание вихря Мёрсена
nexttile
semilogx(E_Mer(1,:),E_Mer(2,:));
title('Expectation Mersenne twister')
x = [1 E(1,end)];
y = [0.5 0.5];
line(x,y,'Color','red','LineStyle','--')

%Дисперсия
nexttile
semilogx(V(1,:),V(2,:));
title('Variance')
x = [1 E(1,end)];
y = [1/12 1/12];
line(x,y,'Color','red','LineStyle','--')

%Дисперсия вихря Мёрсена
nexttile
semilogx(V_Mer(1,:),V_Mer(2,:));
title('Variance Mersenne twister')
x = [1 E(1,end)];
y = [1/12 1/12];
line(x,y,'Color','red','LineStyle','--')