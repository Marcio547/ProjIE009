clear all
clf

%x: estimativas futuras
%xp: estimativas passadas

%inicializacao
x(1,1)  = 30000
v(1,1) = 40;
y = [30000,30110, 30265,30740,30750,31135,31015,31180,31610,31960,31865]
n=11;
Dt = 5;
A=0.2;
B=0.1;

%predicao
printf("primeira predição!\n");
x(2,1) = x(1,1) + Dt*v(1,1)
v(2,1) = v(1,1)
printf("y(2) = %d\n",y(2))



for i=2:n
  printf("update,i = %d\n",i);
  printf("calculando x(%d,%d) e v(%d,%d)\n",i,i,i,i);
  %update
  x(i,i) = x(i,i-1) + A*(y(i)-x(i,i-1)) ;
  x(i,i)
  X(i) = x(i,i);
  v(i,i) = v(i,i-1) + B*((y(i)-x(i,i-1))/Dt);
  v(i,i)
  V(i) = v(i,i);
  %predicao
  printf("predicao proximo estado,i = %d\n",i);
  printf("calculando x(%d,%d) e v(%d,%d)\n",i+1,i,i+1,i);
  x(i+1,i) = x(i,i) + Dt*v(i,i);
  v(i+1,i) = v(i,i);
  
  
  x(i+1,i)
  v(i+1,i)
  Xi(i) = x(i+1,i);
  Vi(i) = v(i+1,i);

 endfor
 
plot(linspace(1,10,10),y(2:11),"x-")
hold on
plot(linspace(1,10,10),X(2:11),"^-")
axis([1 10]) 
hold on
axis("tight")