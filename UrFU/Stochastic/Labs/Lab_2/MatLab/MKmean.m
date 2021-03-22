% clc
% clear
% close

I = importdata('../data/g_integral.txt');

figure(1)
semilogx(I(1,:),I(2,:),'Marker','o');
x = [1 I(1,end)];
y = [8/3 8/3];
hold on;
line(x,y,'Color','red','LineStyle','--')
title('Monte Carlo')
xlabel('N')
ylabel('Function value')

