%clc
%clear
%close

Error = importdata('../data/g_integral_inaccuracy.txt');

figure(2);
semilogx(Error(1,:),Error(2,:),'Marker','o');
x = [1 Error(1,end)];
y = [0 0];
hold on;
line(x,y,'Color','red','LineStyle','--')
title('Monte Carlo inaccuracy')
xlabel('N')
ylabel('Error rate')