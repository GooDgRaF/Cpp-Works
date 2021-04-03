function drawVariance(t)
% a1 = 2;
% a2 = 4;
% a3 = 8;
% a4 = 16;

a1 = 32;
a2 = 64;
a3 = 128;
a4 = 256;

V_1 = importdata("../data/V_noise_a" + a1 + ".txt");
V_2 = importdata("../data/V_noise_a" + a2 + ".txt");
V_3 = importdata("../data/V_noise_a" + a3 + ".txt");
V_4 = importdata("../data/V_noise_a" + a4 + ".txt");

%%%%%%%%%%%%%%%%
nexttile(t,1);
semilogx(V_1(1,:), V_1(2,:), 'Marker', 'o');
hold on;
x = [100 V_1(1,end)];
y = [a1/2 a1/2];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a1);


%%%%%%%%%%%%%%%%
nexttile(t,2);
semilogx(V_2(1,:), V_2(2,:), 'Marker', 'o');
hold on;
x = [100 V_2(1,end)];
y = [a2/2 a2/2];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a2);

%%%%%%%%%%%%%%%%
nexttile(t,3);
semilogx(V_3(1,:), V_3(2,:), 'Marker', 'o');
hold on;
x = [100 V_3(1,end)];
y = [a3/2 a3/2];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a3);

%%%%%%%%%%%%%%%%
nexttile(t,4);
semilogx(V_4(1,:), V_4(2,:), 'Marker', 'o');
hold on;
x = [100 V_4(1,end)];
y = [a4/2 a4/2];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a4);
end

