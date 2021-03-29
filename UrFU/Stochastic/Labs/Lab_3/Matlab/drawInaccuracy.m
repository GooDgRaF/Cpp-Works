function drawInaccuracy(name_of_method_string, title_string)

N = "_100";
N_set = importdata('../data/Source/N_set.txt');
inaccuracy = zeros(1,length(N_set));

for i = 1:length(N_set)
    figure(2);
    S = importdata('../data/Source/'+ name_of_method_string + N + '.txt');
    h = histogram(S,'Normalization','pdf');
    sigma = mean_square_deviation(h);
    inaccuracy(i) = sigma;
    close
    N = N + "0";
end

hold on;
ax = gca;
ax.XScale = 'log';
ax.YScale = 'log';
plot(N_set, inaccuracy, 'Marker', 'o');

title(title_string + ' inaccuracy')
hold off;
end

