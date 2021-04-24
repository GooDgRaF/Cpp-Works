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
Times = importdata("C:/DATA/sample_TIMES.txt");
h = importdata("C:/DATA/sample_h.txt");
T = importdata("C:/DATA/sample_T.txt");
i_max = importdata("C:/DATA/sample_i_max.txt");
St = tabularTextDatastore("C:/DATA/sample_x0="+ x0 +"_a="+ a +"_x_="+ x_ + "_T="+ T + "_eps="+ eps +".txt");   
tallSt = tall(St);


for i = 1:length(Times)
    figure()
    st = gather(tallSt(:,i));
    X = table2array(st);
    histogram(X,'Normalization','pdf'); %100,
    ax = gca;    
    ylim(ax, [0, 4.5]);
    xlim(ax, [-0.6, 3.5]); 
    title("Realizations: " + i_max + "             T-cut = " + Times(i) + "        x0 = " + x0 + "   a = " + a + "   x\_ = " + x_ + "   eps = " + eps);

    hold on;
    fplot(@(x) density(x,eps,a,x_));
    
set(gcf, 'Position', get(0,'Screensize'));
%path = "assa.png";
path = "Hist___i_max=" + i_max + "x0=" + x0 + "a=" + a + "x_=" + x_ + "eps=" + eps + "T=" + Times(i) + ".png";
exportgraphics(gca, path);

end



