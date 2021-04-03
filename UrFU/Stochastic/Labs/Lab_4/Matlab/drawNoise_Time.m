function drawNoise_Time(T)
a1 = 1;
a2 = 4;
a3 = 8;

% a1 = 16;
% a2 = 32;
% a3 = 64;

h = 0.01;
A_1 = importdata("../data/Source/sampleNoise_a" + a1 + "_T" + T +".txt");
A_2 = importdata("../data/Source/sampleNoise_a" + a2 + "_T" + T +".txt");
A_3 = importdata("../data/Source/sampleNoise_a" + a3 + "_T" + T +".txt");

Time = h:h:T;

%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(3,1);
t.TileSpacing = 'compact';
t.Padding = 'compact';
xlabel(t,'Time');
title(t,'Color noise');

%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A_1);
title("a = " + a1);

%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A_2);
title("a = " + a2);


%%%%%%%%%%%%%%%%%
nexttile;
plot(Time,A_3);
title("a = " + a3);

end

