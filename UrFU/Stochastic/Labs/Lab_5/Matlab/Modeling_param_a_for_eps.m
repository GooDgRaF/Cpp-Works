clc
clear
close all


%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
T = importdata("../data/STOCH_FitzHugh_T__.txt");
X0 = importdata("../data/STOCH_FitzHugh_X0__.txt");
Y0 = importdata("../data/STOCH_FitzHugh_Y0__.txt");
A = importdata("../data/STOCH_FitzHugh_A__.txt");
Eps = importdata("../data/STOCH_FitzHugh_Eps__.txt");
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%

for i = 1:length(A)
    figure()
    hold on
    for k = 1:length(Eps)
        D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," ...
            + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) + "_T="+ T +"__.txt");
        X = [];
        for n = 1:length(D)/100
            X = [X D(100*n,1)];
        end       
        plot(Eps(k), X, '-o');

    title("a = " + A(i));
    xlabel("eps");ylabel("x");
    
   
    end   
     set(gcf, 'Position', get(0,'Screensize'));
    path = i+")STOCH_eps-zone___a=" + A(i)+".png";
     exportgraphics(gca, path);
     close;
end