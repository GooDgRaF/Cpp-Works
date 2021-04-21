function drawVar(dir, Var)

i_max = importdata("../" + dir + "/sample_i_max.txt");
N_max = importdata("../" + dir + "/sample_N_max.txt");
N = importdata("../" + dir + "/sampleN_max=" + N_max + ".txt");

for i=0:i_max   
    V = importdata("../" + dir + "/sample_i" + i + "_variance.txt");
    %nexttile(t,i);    
    semilogx(N, V, 'Marker', 'o');
    hold on;
    drawLine(Var, N_max);     
end
xlabel('N');
title('Variance');
end