P=7; M=10;
d=[1;zeros(P-1,1)];
y=d*ones(1,M);
tren=y(:);
n=0:M*P-1;
stem(n,tren);
xlabel('N');
ylabel('Amplitudinea');
title('Tren de impulsuri unitare');
axis([-0 42 0 1.2])