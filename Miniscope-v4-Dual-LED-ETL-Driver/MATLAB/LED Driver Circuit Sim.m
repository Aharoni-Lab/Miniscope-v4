V1 = 3.3;
V2 = 1.21;
R5 = 10000;

%%
resVals1 = linspace(0,99000,256);
resVals2 = linspace(0,99000,256);
resValsDirect = linspace(10285,1000000,256);
idx = 142;

refCurrentVals = linspace(0,100,256);%850*1.21*1000./(resValsDirect(end:-1:1));
V = [];
C = [];

for count1 = 1:length(resVals1)
    for count2 = 1:length(resVals2)
        
R1 = resVals1(count1);
R3 = resVals2(count2);

R2 = 100000-R1;
R4 = 100000-R3;

%
x = [R1+R2 -R2 0 R1 ;
 -R1 R2+R3+R4 R4 R3;
 0 -R4 R4+R5 R5;
 R1 R3 R5 R1+R3+R5];
y = [V1; 0; -V2; V1-V2];
%
z = linsolve(x,y);
I(1) = z(1)+z(4);
I(2) = z(1)-z(2);
I(3) = z(2)+z(4);
I(4) = z(2)-z(3);
I(5) = z(3)+z(4);
% ['Voltage at divider: ' num2str(R2*I(2)) ' | Current through LED: ' num2str(I(5)*1000*850*-1)]
V(count1,count2) = R2*I(2);
C(count1,count2) = I(5)*1000*850*-1;
    end
end

idx2 = [];
fitCurr = [];
for count = 1:length(resVals1)
    [~, idx2(count)] = min(abs(C(:,count)-refCurrentVals(count)));
%     [C(count,idx2(count)) refCurrentVals(count)]
fitCurr(count) = C(idx2(count),count);
end


V(C<0 | C>100) = nan;
C (isnan(V)) = nan;
figure(1)
subplot(2,2,1)
pcolor(resVals2/1000,resVals1/1000,V);
ylabel('R1 (KOhm)')
xlabel('R3 (KOhm)')
colorbar
shading flat
hold on
plot([1 100], resVals1(idx)/1000*[1 1],'--r','linewidth',2)
hold off
title('Voltage at voltage divider')
subplot(2,2,2)
pcolor(resVals2/1000,resVals1/1000,C);
ylabel('R1 (KOhm)')
xlabel('R3 (KOhm)')
colorbar
shading flat
hold on
plot([1 100], resVals1(idx)/1000*[1 1],'--r','linewidth',2)
plot(resVals2/1000,resVals1(idx2)/1000,'--m','linewidth',2)
hold off
title('LED Current')
subplot(2,2,[3])

plot(resVals2,V(idx,:),'r','linewidth',2);
ylabel('Voltage Divider Voltage (V))')
xlabel('Adjustment Range')
title(['At an R1 of ' num2str(resVals1(idx))]);
subplot(2,2,[4])
plot(C(idx,:),'r','linewidth',2);
hold on
plot(refCurrentVals,'--k','linewidth',2);
plot(fitCurr,'m','linewidth',2);
hold off
xlim([1 length(resVals2)])
ylabel('LED Current (mA)')
xlabel('Adjustment Range')
title(['LED Current']);