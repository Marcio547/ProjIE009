clear all
close all;
pkg load instrument-control

if (exist("serial") == 3)
    disp("Serial: Supported")
else
    disp("Serial: Unsupported")
endif


samples = 2000;

sample_number = 1;
s1 = serial("/dev/ttyACM0", 115200) 

srl_flush(s1);

%res = cast(srl_read(s1,4*sample_number),"char")

%res = cast(srl_read(s1,sample_number),"char")
j=1;


result = srl_read(s1,samples)


%inicializacao
x(1,1)  = result(1)
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





save results.mat result