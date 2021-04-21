clc
close all
clear

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%

dir = "data_N";

Exp = 0;
Var = 1;

figure();
drawExp(dir, Exp);


figure();
drawVar(dir, Var);
%%%%%%%%%%%%%%%%%%%

figure();
drawHist(dir);
