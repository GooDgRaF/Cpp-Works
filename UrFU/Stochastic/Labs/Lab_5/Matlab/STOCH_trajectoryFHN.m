clc
clear
close all


%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
h = 0.01;
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
T = importdata("../data/STOCH_FitzHugh_T__.txt");
X0 = importdata("../data/STOCH_FitzHugh_X0__.txt");
Y0 = importdata("../data/STOCH_FitzHugh_Y0__.txt");
A = importdata("../data/STOCH_FitzHugh_A__.txt");
Eps = importdata("../data/STOCH_FitzHugh_Eps__.txt");
N = importdata("../data/STOCH_FitzHugh_arrayN__.txt");
stringN = "";
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
for i = 1:length(A)   
    for k = 1:length(Eps)
        figure()
        ax = gca;
        ax.YLim = [-2.5 2];
        hold on        
        D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," ...
            + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) + "_T="+ T +"__.txt");
        plot(N,D(:,1)); 
        
if A(i) > 1
    stringN = ". Устойчивый узел"; end
if (1 < A(i) && A(i) < sqrt(1.63))
    stringN = ". Устойчивый фокус";end
if (sqrt(0.37) < A(i) && A(i) < 1)    
    stringN = ". Неустойчивый фокус";end
if (0 < A(i) && A(i) < sqrt(0.37))    
    stringN = ". Неустойчивый узел";end
if (A(i) == 1)    
    stringN = ". Центр";end
title("a = " + A(i) + stringN + "    T=" + T + "  eps=" + Eps(k));
xlabel("Time");ylabel("x");

set(gcf, 'Position', get(0,'Screensize'));
path = i+"."+k+")PHASE___a=" + A(i) + "  eps=" + Eps(k)+ "--T=" + T + ".png";
exportgraphics(gca, path);
close;
    end
end



