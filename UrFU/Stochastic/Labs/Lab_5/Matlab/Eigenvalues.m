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
stringN = "";
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
L1 = zeros(1, length(A));
L2 = zeros(1, length(A));
%%%%%%%%%
%%%%%%%%%
for t = 1:length(T)
for k = 1:length(Eps)
    figure()
    hold on
    
    fplot(@(x) eigenvaluePlus(x),[1 3],'--r','LineWidth',2);
    fplot(@(x) eigenvalueMinus(x),[1 3],'--b','LineWidth',2);
    
    for i = 1:length(A) 
      D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) + "_T="+ T(t) +"__.txt");
      Eig = eig(cov(D(:,1),D(:,2)));
      L1(i) = eps^2.*Eig(1); L2(i) = eps^2.*Eig(2);
    end
plot(A,L1,'b','LineWidth',1);
plot(A,L2,'r','LineWidth',1);
title("Eigenvalues   eps=" + Eps(k) + "  T=" + T(t));
xlabel("a");

legend("\lambda_1 - точное","\lambda_2 - точное",...
    "\lambda_1 - численное","\lambda_2 - численное");

set(gcf, 'Position', get(0,'Screensize'));
path = "Eigenvalues___T=" + T(t)+ "eps=" + Eps(k) + ".png";
  exportgraphics(gca, path);
  close;
    
end
end


