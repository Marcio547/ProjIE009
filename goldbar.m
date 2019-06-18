clear all
clf




x(1) = 1000

y = [1030, 989,1017,1009,1013,979,1008,1042,1012,1011]
for i=1:10
  K=1/i;
  x(i+1) = x(i) + K*(y(i) - x(i));
endfor

x(1:10) = x(2:11)

 
plot(linspace(1,10,10),y)
hold on
plot(linspace(1,10,10),x(1:10))
axis([1 10]) 
