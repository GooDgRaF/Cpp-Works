clc
clear
close all


%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%

%PARAMETRS

%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
T = importdata("../data/FitzHugh_T__.txt");
Y0 = importdata("../data/FitzHugh_Y0__.txt");
A = importdata("../data/FitzHugh_A__.txt");
N = importdata("../data/FitzHugh_arrayN__.txt");
stringN = "";
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%
for i = 1:length(A)
    figure()
    for k = 1:length(Y0) 
        hold on
        D = importdata("../data/FitzHugh_a="+ A(i) +"_y0="+ Y0(k) +"__.txt");
        plot(N,D(:,1)); 
        plot(N,D(:,2));
    end
    
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
xlabel("Time");ylabel("X");

set(gcf, 'Position', get(0,'Screensize'));
path = i+")PHASE___a=" + A(i) + "--T=" + T + ".png";
exportgraphics(gca, path);
close;
    
end



