clear all
close all;
pkg load instrument-control

if (exist("serial") == 3)
    disp("Serial: Supported")
else
    disp("Serial: Unsupported")
endif

%desired number of samples
samples = 50;

%choose serial port and baud rate
s1 = serial("/dev/ttyACM0", 115200) 


%clear buffer
srl_flush(s1);

%collects new samples
result = srl_read(s1,samples);
j=1;
num=0.00;
%result = cast(result,"double");
digits = 0;
res = 0;
for i=1:(sizeof(result)-1)
  i
  while(result(i) != 95)
    i++;
  endwhile
  printf("iniciou protocolo\n");
  j=i;
  k=1;
  while(result(j) != 94)      
    num(k) = result(j);
    j++;
    k++;
  endwhile
  k=1;
  printf("pegou todos algarismos\n");
  while(num(k) != 46)
    %res = (num(k)-48)*100 + (num(k+1)-48)*10 + (num(k+2);
    digits++;  
    k++;  
  endwhile
  for l=digits:1
    res= res + num(l)*10^(digits-l);
      
  endfor
endfor
%  if(result(i) == 95 && i < sizeof(result))
%  i++;
%    while(result(i) != 94)
%      num = cast(num + (10^(j))* (result(i)-48),"double");
      
%        j++;
%        i++;
%    endwhile

%  endif
% endfor



%save to file
save results.mat result