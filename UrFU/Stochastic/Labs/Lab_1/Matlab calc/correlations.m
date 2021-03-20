clc
clear
close
Cor = importdata('../data/Cor.txt');
Cor_Mer = importdata('../data/Cor_Mer.txt');
Cor2N = importdata('../data/Cor2N.txt');
Cor2N_Mer = importdata('../data/Cor2N_mer.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Amount of data')
%hold on;

%Корреляция
nexttile
semilogx(Cor(1,:),Cor(2,:));
title('Сorrelation')
x = [1 Cor(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')

%Корреляция вихря Мёрсена
nexttile
semilogx(Cor_Mer(1,:),Cor_Mer(2,:));
title('Сorrelation Mersenne twister')
x = [1 Cor(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')

%Корреляция двойного набора
nexttile
semilogx(Cor2N(1,:),Cor2N(2,:));
title('Сorrelation 2N')
x = [1 Cor(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')

%Корреляция вихря Мёрсена двойной набор
nexttile
semilogx(Cor2N_Mer(1,:),Cor2N_Mer(2,:));
title('Сorrelation Mersenne twister 2N')
x = [1 Cor(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')