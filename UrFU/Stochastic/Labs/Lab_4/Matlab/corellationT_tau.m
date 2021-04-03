function corellationT_tau(n)
M = importdata("../data/Source/sample10_N" + n + ".txt");
Phi = zeros(1,10);
X = 0:1:9;

for j = 1:10
    Phi(j) = dot(M(:,1), M(:,j)) / 10;    
end

plot(X,Phi);
hold on;

p = n; q = 0;
while mod(p,10) == 0
    q = q + 1;
    p = p / 10;
end
fplot(@(x) 0.5*exp(-x + (1 + 2*(q - 1))), [-1,10]);
end

