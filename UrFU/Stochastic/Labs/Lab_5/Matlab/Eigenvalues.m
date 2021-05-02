clc
clear
close all

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%

%PARAMETRS

%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
T = importdata("../data/STOCH_FitzHugh_T__.txt");
X0 = importdata("../data/STOCH_FitzHugh_X0__.txt");
Y0 = importdata("../data/STOCH_FitzHugh_Y0__.txt");
A = importdata("../data/STOCH_FitzHugh_A__.txt");
Eps = importdata("../data/STOCH_FitzHugh_Eps__.txt");
stringN = "";
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
L1 = zeros(1, length(A));
L2 = zeros(1, length(A));
for k = 1:length(Eps)
    figure()
    for i = 1:length(A) 
        hold on
      D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) +"__.txt");
      Eig = eig(cov(D(:,1),D(:,2)));
      L1(i) = Eig(1); L2(i) = Eig(2);
    end
plot(A,L1);
plot(A,L2);
title("Eigenvalues   eps=" + Eps(k) + "  T=" + T);
xlabel("a");

set(gcf, 'Position', get(0,'Screensize'));
path = k+")Eigenvalues___eps=" + Eps(k) + "--T=" + T + ".png";
exportgraphics(gca, path);
close;
    
end



