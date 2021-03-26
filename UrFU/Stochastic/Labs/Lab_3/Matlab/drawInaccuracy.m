function drawInaccuracy(name_of_method_string, title_string)

N = "_100";
N_set = importdata('../data/Source/N_set.txt');
inaccuracy = zeros(1,length(N_set));

for i = 1:length(N_set)
    S = importdata('../data/Source/'+ name_of_method_string + N + '.txt');
    h = histogram(S,'Normalization','pdf');
    sigma = mean_square_deviation(h);
    inaccuracy(i) = sigma;
    close
    N = N + "0";
end

semilogx(N_set, inaccuracy, 'Marker', 'o');
hold on;
title(title_string + ' inaccuracy')
x = [100 N_set(end)];
y = [0 0];
line(x,y,'Color','red','LineStyle','--')
hold off;
end

