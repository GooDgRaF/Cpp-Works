function double = density(x,sigma,I)
C = sigma^2/I;
double = C/sigma^2*exp(2/sigma^2*(x^2 - x^4/4));
end

