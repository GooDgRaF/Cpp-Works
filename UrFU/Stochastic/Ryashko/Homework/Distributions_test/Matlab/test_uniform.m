clc
close all
clear

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%

dir = "data_U";
Exp = 0.5;
Var = 1/12;

% figure();
% drawExp(dir, Exp);
% 
% 
% figure();
% drawVar(dir, Var);

%%%%%%%%%%%%%%%%%%%

figure();
drawHist(dir, @(x) 1);


