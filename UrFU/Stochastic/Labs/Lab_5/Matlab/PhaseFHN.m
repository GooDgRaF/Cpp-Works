clc
clear
close all


%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t, 'Phase portraits');

%%%%

T = 500;
X_init = [0, 0];
A = [0.9, 0.89, 0.88, 0.85];
%%%%
G = importdata("../data/FitzHugh_grid.txt");








%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
a = A(1);
D = importdata("../data/FitzHugh_a_"+ a +"_.txt");

if a > 1
    stringN = ". Устойчивый узел"; end
if (1 < a && a < sqrt(1.63))
    stringN = ". Устойчивый фокус";end
if (sqrt(0.37) < a && a < 1)    
    stringN = ". Неустойчивый фокус";end
if (0 < a && a < sqrt(0.37))    
    stringN = ". Неустойчивый узел";end

nexttile;
plot(D(:,1),D(:,2)); 
title("a = " + a + stringN);
xlabel("x");ylabel("y");


  
    
%%%%%%%%%%%%%%%%
a = A(2);
D = importdata("../data/FitzHugh_a_"+ a +"_.txt");

if a > 1
    stringN = ". Устойчивый узел"; end
if (1 < a && a < sqrt(1.63))
    stringN = ". Устойчивый фокус";end
if (sqrt(0.37) < a && a < 1)    
    stringN = ". Неустойчивый фокус";end
if (0 < a && a < sqrt(0.37))    
    stringN = ". Неустойчивый узел";end

nexttile;
plot(D(:,1),D(:,2)); 
title("a = " + a + stringN);
xlabel("x");ylabel("y");


%%%%%%%%%%%%%%%%
a = A(3);
D = importdata("../data/FitzHugh_a_"+ a +"_.txt");

if a > 1
    stringN = ". Устойчивый узел"; end
if (1 < a && a < sqrt(1.63))
    stringN = ". Устойчивый фокус";end
if (sqrt(0.37) < a && a < 1)    
    stringN = ". Неустойчивый фокус";end
if (0 < a && a < sqrt(0.37))    
    stringN = ". Неустойчивый узел";end

nexttile;
plot(D(:,1),D(:,2)); 
title("a = " + a + stringN);
xlabel("x");ylabel("y");


%%%%%%%%%%%%%%%%
a = A(4);
D = importdata("../data/FitzHugh_a_"+ a +"_.txt");

if a > 1
    stringN = ". Устойчивый узел"; end
if (1 < a && a < sqrt(1.63))
    stringN = ". Устойчивый фокус";end
if (sqrt(0.37) < a && a < 1)    
    stringN = ". Неустойчивый фокус";end
if (0 < a && a < sqrt(0.37))    
    stringN = ". Неустойчивый узел";end

nexttile;
plot(D(:,1),D(:,2)); 
title("a = " + a + stringN);
xlabel("x");ylabel("y");


function dXdt = FHN(t,X, a)
dx1 = 1/10*(X(1) - X(2) - X(1)*X(1)*X(1)/3);
dx2 = X(1) + a;
dXdt = [dx1; dx2];
end
