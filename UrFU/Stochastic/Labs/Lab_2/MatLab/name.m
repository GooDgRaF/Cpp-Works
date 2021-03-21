clc
clear
close

I = importdata('../data/g_integral.txt');
Error = importdata('../data/g_integral_inaccuracy.txt');

semilogx(I(1,:),I(2,:),'Marker','o');
x = [1 I(1,end)];
y = [8/3 8/3];
line(x,y,'Color','red','LineStyle','--')
title('Monte Carlo')
xlabel('N')
ylabel('Function value')

figure;
semilogx(Error(1,:),Error(2,:),'Marker','o');
x = [1 Error(1,end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
title('Monte Carlo inaccuracy')
xlabel('N')
ylabel('Error rate')