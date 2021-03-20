clc
clear
close

%D = importdata('../data/Source_data/10000000.txt');
%D_Mer = importdata('../data/Source_data/Mer10000000.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Amount of data')
%%%%%
x = [0.05 0.15 0.25 0.35 0.45 0.55 0.65 0.75 0.85 0.95];
y = [10,10,11,12,7,10,10,11,12,7];
%%%%%
%Гистограмма
nexttile
bar(x,y,0.95);
%Гистограмма вихря Мёрсена
nexttile
%histogram(D_Mer, nbins, 'Normalization','probability');