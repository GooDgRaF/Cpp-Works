%InterSpike Intervals
clc
clear
close all

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
T = importdata("../data/STOCH_FitzHugh_T__.txt");
X0 = importdata("../data/STOCH_FitzHugh_X0__.txt");
Y0 = importdata("../data/STOCH_FitzHugh_Y0__.txt");
A = importdata("../data/STOCH_FitzHugh_A__.txt");
Eps = importdata("../data/STOCH_FitzHugh_Eps__.txt");
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%
h = 0.01;
N = T/h;
%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%% eps = 0.001 0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.1
for i = 1:length(A)
    figure()
    hold on
    C_v = [];
    for k = 1:length(Eps)
        D = importdata("../data/STOCH_FitzHugh_equilibrium=" + X0(i)+ "," ...
            + Y0(i)+ "_a=" + A(i) + "_eps=" + Eps(k) + "_T="+ T +"__.txt");
        x = D(:,1); clear D;
        spike_time = zeros(1, length(x));          
        is_spike_begins = false;
        for n = 1:length(x)
            if (x(n) > 0)
                is_spike_begins = true;
            end
            if (is_spike_begins == true && x(n) < 0)
               is_spike_begins = false;
               spike_time(n) = n*h;
            end
        end
        spike_time(spike_time == 0) = [];
        tau = zeros(1,length(spike_time) - 1);
        for n = 1:length(tau)
           tau(n) = spike_time(n + 1) - spike_time(n); 
        end
        
        Cv = sqrt(var(tau))/mean(tau);     
        C_v = [C_v Cv];
        

    end   
        
    ax = gca;
        ax.YLim = [0 1];
        plot(Eps, C_v);
    
    title("Зависимость коэффициента вариации от eps.    a = " ...
                                                        + A(i) + "  T="+ T);
    xlabel("eps");ylabel("C_v"); 
    
     set(gcf, 'Position', get(0,'Screensize'));
    path = "STOCH_CV___a=" + A(i)+ "_T="+ T +".png";
     exportgraphics(gca, path);
     close;
end