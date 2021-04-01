function drawVariance(t)

V1 = importdata("../data/V_noise_a1.txt");
V10 = importdata("../data/V_noise_a10.txt");
V100 = importdata("../data/V_noise_a100.txt");

%%%%%%%%%%%%%%%%
nexttile(t,1);
semilogx(V1(1,:), V1(2,:), 'Marker', 'o');
hold on;
x = [100 V1(1,end)];
y = [0.5 0.5];
line(x,y,'Color','red','LineStyle','--')
title('a = 1');


%%%%%%%%%%%%%%%%
nexttile(t,2);
semilogx(V10(1,:), V10(2,:), 'Marker', 'o');
hold on;
x = [100 V10(1,end)];
y = [5 5];
line(x,y,'Color','red','LineStyle','--')
title('a = 10');

%%%%%%%%%%%%%%%%
nexttile(t,3);
semilogx(V100(1,:), V100(2,:), 'Marker', 'o');
hold on;
x = [100 V100(1,end)];
y = [50 50];
line(x,y,'Color','red','LineStyle','--')
title('a = 100');
end

