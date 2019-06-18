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

%for i=1:sizeof(result)
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