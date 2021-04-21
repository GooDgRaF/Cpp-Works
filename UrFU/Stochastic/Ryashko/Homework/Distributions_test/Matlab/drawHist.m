function drawHist()

i = 0;
N_max = importdata("../data/sample_N_max.txt");
N = importdata("../data/sampleN_max=" + N_max + ".txt");

t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t,'Histogram');
for k=length(N) - 3:length(N)
    
   S = importdata("../data/sample_i" + i + "_N" + N(k)+".txt");
   nexttile;       
   histogram(S, 100,'Normalization','pdf');
   title("N = " + N(k));
end
end