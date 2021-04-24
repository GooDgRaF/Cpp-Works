function double = density(x,sigma,a,x_)
double = 1./(sigma.*sigma) .* exp(-a./(sigma.*sigma).*(x - x_).*(x - x_));
end

