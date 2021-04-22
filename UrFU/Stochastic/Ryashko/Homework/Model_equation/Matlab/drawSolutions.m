clc
clear
close all

%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%
a = 1.1;
x0 = 1.1;
x_ = 1.1;
%%%%%%%%%%%
%%%%%%%%%%%
T = importdata("../data/sample_T.txt");
h = importdata("../data/sample_h.txt");
eps = importdata("../data/sample_eps.txt"); %Аддитивный шум
N = 0:h:T;

S = importdata("../data/sample_x0="+ x0 +"_a="+ a +"_x_="+ x_ + "_T="+ T + "_eps="+ eps +".txt");

i_max = importdata("../data/sample_i_max.txt");
figure()
for i=1:i_max   
    plot(N, S(i,:));
    hold on;
end
title("Realizations: " + i_max + "             x0 = " + x0 + "   a = " + a + "   x\_ =" + x_ + "   eps = " + eps);
xlabel("Time");
