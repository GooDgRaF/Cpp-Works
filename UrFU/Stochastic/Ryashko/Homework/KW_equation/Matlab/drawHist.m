clc
clear
close all

%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%
a = 2;
x0 = 0;
x_ = 2;
eps = 0.1;
I = 1.28*10^86;
T_max = 10;
%%%%%%%%%%%
%%%%%%%%%%%
Nbins = importdata("../data/HIST_sample_bins.txt");
h = importdata("../data/HIST_sample_h.txt");
i_max = importdata("../data/HIST_sample_i_max.txt");

S = importdata("../data/HIST_sample_x0="+ x0 +"_a="+ a +"_x_="+ x_ + "_T="+ T_max + "_eps="+ eps +".txt");   
for n = 2:length(Nbins)
    figure()
    histogram(S(:,n),150,'Normalization','pdf');
    ax = gca;    
    ylim(ax,[0 6]);
    xlim(ax,[-2 2]); 
    title("Realizations: " + i_max + "             T-cut = " + Nbins(n)*h + "        x0 = " + x0 + "   a = " + a + "   x\_ = " + x_ + "   eps = " + eps);

    hold on;
    fplot(@(x) density(x,eps,I));
    
 set(gcf, 'Position', get(0,'Screensize'));
path = "Hist___i_max=" + i_max + "x0=" + x0 + "a=" + a + "x_=" + x_ + "eps=" + eps + "T=" + T_max + "N=" + Nbins(n) + ".png";
exportgraphics(gca, path);
close;

end



