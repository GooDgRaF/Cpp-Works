clc
clear
close all

i = 1;
for T = [1, 10, 100, 1000]
    figure(i);    
    drawNoise_Time(T);
    i = i + 1;
end