clear
clc
close all
figure

% Carto de base

[X,Y] = meshgrid(0:99,0:5:499);
baseMap = (peaks(100)+5).*20; % Temp 

subplot(1,2,1)
surf(X,Y,baseMap)
title('Base map');
xlabel('Commande Puissance (%)')
ylabel('Vitesse (Tr/min)')
zlabel('Commande (%255)')

% Carto rapport?e i[32][32]

interpMap32 = round(resizem(baseMap,[32 32]));

interpMap32(interpMap32>255) = 255;
interpMap32(interpMap32<0) = 0;

X_index = resizem(X,[32 32]);
Y_index = resizem(Y,[32 32]);

subplot(1,2,2)
surf(interpMap32)
title('map x32');
xlabel('Commande Puissance (%)')
ylabel('Vitesse (Tr/min)')
zlabel('Commande (%255)')

index32 = [X_index(1,:);Y_index(:,1)'];

dlmwrite('map_inter_i32.csv',interpMap32)
dlmwrite('map_index_i32.csv',index32)

% Volontairement bas niveau
% pour pouvoir transposer en C

% [Xq,Yq] = meshgrid(-3:0.25:3);
% 
% Vq = interp2(X,Y,V,Xq,Yq,'linear');
% 
% figure
% surf(Xq,Yq,Vq);
% title('Cubic Interpolation Over Finer Grid');