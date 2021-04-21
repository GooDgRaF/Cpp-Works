function drawExp(dir, Exp)

i_max = importdata("../" + dir + "/sample_i_max.txt");
N_max = importdata("../" + dir + "/sample_N_max.txt");
N = importdata("../" + dir + "/sampleN_max=" + N_max + ".txt");

for i=0:i_max   
    E = importdata("../" + dir + "/sample_i" + i + "_expectation.txt");    
    semilogx(N, E, 'Marker', 'o');
    hold on;
    drawLine(Exp, N_max);
end
xlabel('N');
title('Expectation');
end

