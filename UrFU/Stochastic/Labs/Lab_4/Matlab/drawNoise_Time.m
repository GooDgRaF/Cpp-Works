function drawNoise_Time(T)

h = 0.01;
A1 = importdata("../data/Source/sampleNoise_a1_T" + T +".txt");
A10 = importdata("../data/Source/sampleNoise_a10_T" + T +".txt");
A100 = importdata("../data/Source/sampleNoise_a100_T" + T +".txt");

Time = h:h:T;

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(3,1);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Time');
title(t,'Noise');

%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A1);


%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A10);


%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A100);

end

