clc
clear
close

D = importdata('../data/Source_data/10000000.txt');
D_Mer = importdata('../data/Source_data/Mer10000000.txt');
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,1);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Amount of data')
%%%%%
nbins = 10;
%%%%%
%Гистограмма
nexttile
histogram(D, nbins, 'Normalization','probability');

%Гистограмма вихря Мёрсена
nexttile
histogram(D_Mer, nbins, 'Normalization','probability');