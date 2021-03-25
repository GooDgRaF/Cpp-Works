clc
clear
close

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t,'Box-Mueller');

name = "sampleBM";
%%%%%%%%
nexttile
S_10e3 = importdata('../data/Source/'+ name +'_1000.txt');
h_10e3 = histogram(S_10e3,10);
maxS_10e3 = max(h_10e3.Values);
K_10e3 = maxS_10e3/2.506;
hold on;
fplot(@(x) K_10e3*(1\sqrt(2*pi) * exp(-(x^2/2))));title('N = 100');

%%%%%%%%
nexttile
S_10e4 = importdata('../data/Source/'+ name +'_10000.txt');
h_10e4 = histogram(S_10e4);
maxS_10e4 = max(h_10e4.Values);
K_10e4 = maxS_10e4/2.506;
hold on;
fplot(@(x) K_10e4*(1\sqrt(2*pi) * exp(-(x^2/2))));title('N = 1 000');

%%%%%%%%
nexttile
S_10000 = importdata('../data/Source/'+ name +'_100000.txt');
h_10e5 = histogram(S_10000);
maxS_10e5 = max(h_10e5.Values);
K_10e5 = maxS_10e5/2.506;
hold on;
fplot(@(x) K_10e5*(1\sqrt(2*pi) * exp(-(x^2/2))));
title('N = 10 000');

%%%%%%%%
nexttile
S_10e6 = importdata('../data/Source/'+ name +'_1000000.txt');
h_10e6 = histogram(S_10e6);
maxS_10e6 = max(h_10e6.Values);
K_10e6 = maxS_10e6/2.506;
hold on;
fplot(@(x) K_10e6*(1\sqrt(2*pi) * exp(-(x^2/2))));
title('N = 100 000');