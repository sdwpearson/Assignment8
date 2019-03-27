% Plots the time vs cores for running the ants job in various degrees of
% parallelization.

clear all;

times = [425,446,483,525,545,599,630,723,791,907,1042,1223,1514,1986,2896,5779];
cores = 1:16;
cores = flip(cores);

figure;
plot(cores, times);
xlabel('Number of parallel cores')
ylabel('Walltimes (s)')
title('Scaling analysis of ants job')

