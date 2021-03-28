function drawHist(name_of_method_string, title_string)
%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%
t = tiledlayout(2,2);
t.TileSpacing = 'compact';
t.Padding = 'compact';
title(t,title_string);

%%%%%%%%
nexttile
S_10e3 = importdata('../data/Source/'+ name_of_method_string +'_1000.txt');
h_10e3 = histogram(S_10e3,'Normalization','pdf');
hold on;
fplot(@(x) normal_density_function(x));title('N = 1 000');

%%%%%%%%
nexttile
S_10e4 = importdata('../data/Source/'+ name_of_method_string +'_10000.txt');
h_10e4 = histogram(S_10e4,'Normalization','pdf');
hold on;
fplot(@(x)normal_density_function(x));title('N = 10 000');

%%%%%%%
nexttile
S_10000 = importdata('../data/Source/'+ name_of_method_string +'_100000.txt');
h_10e5 = histogram(S_10000,'Normalization','pdf');
hold on;
fplot(@(x) normal_density_function(x));
title('N = 100 000');

%%%%%%%
nexttile
S_10e6 = importdata('../data/Source/'+ name_of_method_string +'_1000000.txt');
h_10e6 = histogram(S_10e6,'Normalization','pdf');
hold on;
fplot(@(x) normal_density_function(x));
title('N = 1 000 000');

end

