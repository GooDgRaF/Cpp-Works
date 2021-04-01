clc
clear
close all

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(1,3);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Iterations');
title(t, 'Expectation');

%drawExpectation(t);

drawVariance(t);

