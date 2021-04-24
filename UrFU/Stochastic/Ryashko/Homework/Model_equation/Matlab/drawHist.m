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
h = importdata("C:/DATA/sample_h.txt");
%h = importdata("../data/sample_h.txt");
T_max = 10;
i_max = importdata("../data/sample_i_max.txt");
S = importdata("../data/sample_x0="+ x0 +"_a="+ a +"_x_="+ x_ + "_T="+ T_max + "_eps="+ eps +".txt");   
for T = 1:T_max/10:T_max 
    figure()
    histogram(S(:,T),'Normalization','pdf'); %100,
    ax = gca;    
    ylim(ax, [0, 4.5]);
    xlim(ax, [-0.6, 2]); 
    title("Realizations: " + i_max + "             T-cut = " + T + "        x0 = " + x0 + "   a = " + a + "   x\_ = " + x_ + "   eps = " + eps);

    hold on;
    fplot(@(x) density(x,eps,a,0.5));
    
set(gcf, 'Position', get(0,'Screensize'));
path = "Hist___i_max=" + i_max + "x0=" + x0 + "a=" + a + "x_=" + x_ + "eps=" + eps + "T=" + T + ".png";
exportgraphics(gca, path);

end



