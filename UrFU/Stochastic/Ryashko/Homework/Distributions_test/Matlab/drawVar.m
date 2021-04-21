function drawVar()

i_max = importdata("../data_U/sample_i_max.txt");
N_max = importdata("../data_U/sample_N_max.txt");
N = importdata("../data_U/sampleN_max=" + N_max + ".txt");

for i=0:i_max   
    V = importdata("../data_U/sample_i" + i + "_variance.txt");
    %nexttile(t,i);    
    semilogx(N, V, 'Marker', 'o');
    hold on;
    x = [100 N_max];
    y = [1/12 1/12];
    line(x,y,'Color','red','LineStyle','--')      
end
xlabel('N');
title('Variance');
end