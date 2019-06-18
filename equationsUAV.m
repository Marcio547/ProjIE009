clear all
close all
clf

%primeira parte


x0 = 30000
v0 = 50
a = 8

t = linspace(1,50,50);
%x(t) = x(1) + v0*(t-1)
x = x0 +v0*t;
x1 = x0 + v0*(linspace(1,15,15));
x2 = x0+v0*15 + v0*(linspace(15,50,36) -15)+ 0.5*a*(linspace(15,50,36) - 15).^2;


%t = linspace(15,50,37);
t= linspace(15,50,36);
y = x0 +v0*t +0.5*a*t.^2 -x(t) + 30000;



plot(linspace(1,15,15),x1)
hold on
plot(linspace(15,50,36),x2)






%plot(linspace(1,50,50),x(1:50)/1000)
%hold on
%p =plot(14,31.534,'ok','markerfacecolor','k');
%axis([1 50])

%set(gcf, "position", [300,100,1000,100])
v1 = v0
v2=v0 + a*(linspace(15,50,36)-15);


figure()


plot(v1)
hold on
plot(linspace(15,50,36),v2)