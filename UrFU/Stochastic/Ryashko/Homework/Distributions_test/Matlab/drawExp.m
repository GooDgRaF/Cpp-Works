function drawExp()

i_max = importdata("../data_U/sample_i_max.txt");
N_max = importdata("../data_U/sample_N_max.txt");
N = importdata("../data_U/sampleN_max=" + N_max + ".txt");

for i=0:i_max   
    E = importdata("../data_U/sample_i" + i + "_expectation.txt");
    %nexttile(t,i);    
    semilogx(N, E, 'Marker', 'o');
    hold on;
    x = [100 N_max];
    y = [0.5 0.5];
    line(x,y,'Color','red','LineStyle','--')      
end
xlabel('N');
title('Expectation');
end

