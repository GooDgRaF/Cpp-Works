clc
clear
close all
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t, 'Correlation, a = 1');

n = [1000 10000 100000 1000000];

%%%%%%%%%%%%%%%%
for k = n
nexttile
corellationT_tau(k);
title("N = " + k);
end






