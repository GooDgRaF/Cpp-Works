clc
clear
close all

%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%
a = 3;
x0 = 0;
x_ = 2;
eps = 1;
%%%%%%%%%%%
%%%%%%%%%%%
h = importdata("../data/sample_h.txt");
%T_max = importdata("../data/sample_T_max.txt");
i_max = importdata("../data/sample_i_max.txt");




for T = [1,10,100,1000]    
S = importdata("../data/sample_x0="+ x0 +"_a="+ a +"_x_="+ x_ + "_T="+ T + "_eps="+ eps +".txt");   
N = 0:h:T;
figure()
for i=1:i_max   
    plot(N, S(i,:));
    hold on;
end
title("Realizations: " + i_max + "             x0 = " + x0 + "   a = " + a + "   x\_ = " + x_ + "   eps = " + eps);
xlabel("Time");

set(gcf, 'Position', get(0,'Screensize'));
path = "i_max=" + i_max + "x0=" + x0 + "a=" + a + "x_=" + x_ + "eps=" + eps + "T=" + T + ".png";
exportgraphics(gca, path);
end