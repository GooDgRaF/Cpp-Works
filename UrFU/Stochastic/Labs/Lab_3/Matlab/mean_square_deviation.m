function double = mean_square_deviation(histogram)
sigma = 0;
X = histogram.Values;
Ed = histogram.BinEdges;
for i=1:length(X)
    mid = (Ed(i + 1) + Ed(i))/2;
    sigma = sigma +  (X(i) - normal_density_function(mid))^2;
end
sigma = sigma/length(X);
double = sigma;
end

