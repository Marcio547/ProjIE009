clear all
close all
mat = load("results.mat");
load("results.mat");
figure()
L = sizeof(mat)
dist = 20
plot(linspace(0,L,L),result(1:L))
title('Dados do Sensor HCSR04')
ylabel('distancia (cm)')
axis([1 L 0 dist])