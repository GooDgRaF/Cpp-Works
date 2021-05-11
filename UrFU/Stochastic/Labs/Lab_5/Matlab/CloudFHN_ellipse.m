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
p = 0.999;
k = sqrt(-log(1-p));
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
for t=1:length(T)
for i=1:length(A)
    figure()
   x_ = -A(i);
   y_ = A(i)*(1/3*A(i)*A(i) - 1);
   for m = 1:length(Eps)
      hold on
      D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(m) + "_T="+ T(t) +"__.txt");
      plot(D(:,1),D(:,2),'-o','MarkerSize',2, 'LineStyle', 'none'); 
      
      lambda1 = eigenvaluePlus(A(i));
      lambda2 = eigenvalueMinus(A(i));
      
      v1 = eigVectorPlus(A(i));
      v2 = eigVectorMinus(A(i));
      
      v1 = v1/norm(v1);
      v2 = v2/norm(v2);
      
      z1 = @(phi) Eps(m)*k*sqrt(2*lambda1)*cos(phi);
      z2 = @(phi) Eps(m)*k*sqrt(2*lambda2)*sin(phi);
      
      detV = det([v1 v2]);
      
      x_phi = @(phi) x_ + (z1(phi)*v2(2) - z2(phi)*v1(2))/detV;
      y_phi = @(phi) y_ + (z2(phi)*v1(1) - z1(phi)*v2(1))/detV;
      fplot(x_phi, y_phi, [0, 2*pi],'--r','LineWidth',2);
   end
   a = plot(x_, y_, '.','Color','[0 0 0]');
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
title("a = " + A(i) + stringN + "    T=" + T(t) + "  eps=" + Eps(m) +...
        "  p=" + p);
xlabel("x");ylabel("y");

set(gcf, 'Position', get(0,'Screensize'));
path = t+"."+i+"."+m+")STOCH_PHASE_ELLIPSE__a=" + A(i) + "--T=" + T(t)+ ".png";
 exportgraphics(gca, path);
close;
end
end