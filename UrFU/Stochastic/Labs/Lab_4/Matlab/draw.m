clc
clear
close all

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Iterations');
title(t, 'Expectation');

drawExpectation(t);

%drawVariance(t);

