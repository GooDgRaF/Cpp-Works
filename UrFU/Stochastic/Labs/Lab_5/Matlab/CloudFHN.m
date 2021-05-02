clc
clear
close all


%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
T = importdata("../data/STOCH_FitzHugh_T__.txt");
X0 = importdata("../data/STOCH_FitzHugh_X0__.txt");
Y0 = importdata("../data/STOCH_FitzHugh_Y0__.txt");
A = importdata("../data/STOCH_FitzHugh_A__.txt");
%N = importdata("../data/STOCH_FitzHugh_arrayN__.txt");
Eps = importdata("../data/STOCH_FitzHugh_Eps__.txt");
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%

for i=1:length(A)
    figure()
   for k = 1:length(Eps)
      hold on
      D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) +"__.txt");
      plot(D(:,1),D(:,2),'-o','MarkerSize',2, 'LineStyle', 'none');        
   end    
   a = plot(-A(i), A(i)*(1/3*A(i)*A(i) - 1), '.','Color','[0 0 0]');
   a.MarkerSize = 20;
   
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
title("a = " + A(i) + stringN);
xlabel("x");ylabel("y");

set(gcf, 'Position', get(0,'Screensize'));
path = i+")STOCH_PHASE___a=" + A(i) + "--T=" + T + ".png";
exportgraphics(gca, path);
close;
end