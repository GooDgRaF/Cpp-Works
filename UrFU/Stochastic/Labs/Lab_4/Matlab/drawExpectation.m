function drawExpectation(t)
a1 = 2;
a2 = 4;
a3 = 8;
a4 = 16;

% a1 = 32;
% a2 = 64;
% a3 = 128;
% a4 = 256;


E_1 = importdata("../data/E_noise_a" + a1 + ".txt");
E_2 = importdata("../data/E_noise_a" + a2 + ".txt");
E_3 = importdata("../data/E_noise_a" + a3 + ".txt");
E_4 = importdata("../data/E_noise_a" + a4 + ".txt");

%%%%%%%%%%%%%%%%
nexttile(t,1);
semilogx(E_1(1,:), E_1(2,:), 'Marker', 'o');
hold on;
x = [100 E_1(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a1);


%%%%%%%%%%%%%%%%
nexttile(t,2);
semilogx(E_2(1,:), E_2(2,:), 'Marker', 'o');
hold on;
x = [100 E_2(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a2);

%%%%%%%%%%%%%%%%
nexttile(t,3);
semilogx(E_3(1,:), E_3(2,:), 'Marker', 'o');
hold on;
x = [100 E_3(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a3);

%%%%%%%%%%%%%%%%
nexttile(t,4);
semilogx(E_4(1,:), E_4(2,:), 'Marker', 'o');
hold on;
x = [100 E_4(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title("a = " + a4);
end

