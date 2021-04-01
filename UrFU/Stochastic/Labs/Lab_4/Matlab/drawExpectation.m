function drawExpectation(t)

E1 = importdata("../data/E_noise_a1.txt");
E10 = importdata("../data/E_noise_a10.txt");
E100 = importdata("../data/E_noise_a100.txt");

%%%%%%%%%%%%%%%%
nexttile(t,1);
semilogx(E1(1,:), E1(2,:), 'Marker', 'o');
hold on;
x = [100 E1(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title('a = 1');


%%%%%%%%%%%%%%%%
nexttile(t,2);
semilogx(E10(1,:), E10(2,:), 'Marker', 'o');
hold on;
x = [100 E10(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title('a = 10');

%%%%%%%%%%%%%%%%
nexttile(t,3);
semilogx(E100(1,:), E100(2,:), 'Marker', 'o');
hold on;
x = [100 E100(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title('a = 100');
end

