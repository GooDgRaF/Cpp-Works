clc
clear
close

D_100_Mer = importdata('../data/Source_data/Histogram_data/Mer100.txt');
D_10_4_Mer = importdata('../data/Source_data/Histogram_data/Mer10000.txt');
D_10_5_Mer = importdata('../data/Source_data/Histogram_data/Mer100000.txt');
D_10_6_Mer = importdata('../data/Source_data/Histogram_data/Mer1000000.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t,'Histogram Mersenne twister')
%%%%%
x = 0.05:0.1:0.95;
y = 0.13;
%%%%%
%Гистограмма1
ax = nexttile;
bar(x,D_100_Mer,0.95);
title('N = 100');
ax.YLim = [0 0.2];

%Гистограмма2
ax = nexttile;
bar(x,D_10_4_Mer,0.95);
title('N = 10^4');
ax.YLim = [0 y];

%Гистограмма3
ax = nexttile;
bar(x,D_10_5_Mer,0.95);
title('N = 10^5');
ax.YLim = [0 y];

%Гистограмма4
ax = nexttile;
bar(x,D_10_6_Mer,0.95);
title('N = 10^6');
ax.YLim = [0 y];













