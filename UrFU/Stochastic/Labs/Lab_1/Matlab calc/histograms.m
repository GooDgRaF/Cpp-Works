clc
clear
close

D_100 = importdata('../data/Source_data/Histogram_data/100.txt');
D_10_4 = importdata('../data/Source_data/Histogram_data/10000.txt');
D_10_5 = importdata('../data/Source_data/Histogram_data/100000.txt');
D_10_6 = importdata('../data/Source_data/Histogram_data/1000000.txt');
%D_Mer = importdata('../data/Source_data/Mer10000000.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t,'Histogram')
%%%%%
x = 0.05:0.1:0.95;
y = 0.13;
%%%%%
%Гистограмма1
ax = nexttile;
bar(x,D_100,0.95);
title('N = 100');
ax.YLim = [0 0.2];

%Гистограмма2
ax = nexttile;
bar(x,D_10_4,0.95);
title('N = 10^4');
ax.YLim = [0 y];

%Гистограмма3
ax = nexttile;
bar(x,D_10_5,0.95);
title('N = 10^5');
ax.YLim = [0 y];

%Гистограмма4
ax = nexttile;
bar(x,D_10_6,0.95);
title('N = 10^6');
ax.YLim = [0 y];




%Гистограмма вихря Мёрсена
%nexttile
%bar(x,y);











