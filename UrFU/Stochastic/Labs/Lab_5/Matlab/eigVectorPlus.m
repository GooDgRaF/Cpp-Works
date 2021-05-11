function vector = eigVectorPlus(x)
double = (-200*(x^2-1))/(sqrt(10000*x^8-40000*x^6+80200*x^4-80400*x^2+40001)...
             + 100*x^4 - 200*x^2 + 1);
vector = [double; 1];
end

