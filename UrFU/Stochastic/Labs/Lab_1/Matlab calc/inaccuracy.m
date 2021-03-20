clc
clear
close
I = importdata('../data/Inaccuracy.txt');
I_Mer = importdata('../data/Inaccuracy_Mer.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,1);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Amount of data')

%Отклонение
nexttile
semilogx(I(1,:),I(2,:));
title('Inaccuracy')
x = [1 I(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')

%Отклонение вихря Мёрсена
nexttile
semilogx(I_Mer(1,:),I_Mer(2,:));
title('Inaccuracy Mersenne twister')
x = [1 I(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')