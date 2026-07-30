#include<stdio.h>
int main(){
int n,i,j;
int bt[20],wt[20],tat[20],p[20];
int temp;
float total_wt =0, total_tat =0;
float avg_wt = 0, avg_tat=0;

printf("enter nunmber of processes: ");
scanf("%d",&n);

//Input Burst Time
printf("\nEnter Burst Time for each process: ");
for(i=0;i<n;i++){
p[i]=i+1;
printf("P%d: ",i+1);
scanf("%d",&bt[i]);
}



//Sort according to Burst Time
for(i=1;i<n-1;i++){
for(j=i+1;j<n;j++){
if(bt[i]>bt[j]){
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;

temp = p[i];
p[i] = p[j];
p[j] = temp;
}
}
}

//Calculate Waiting Time
wt[0]= 0;
for(i= 1;i<n;i++){


wt[i] =wt[i-1]+bt[i-1];
}


//Calculate Turnaround Time
for(i=0;i<n;i++){
tat[i]=wt[i]+bt[i];

total_wt += wt[i];
total_tat += tat[i];

}

avg_wt = total_wt /n;
avg_tat = total_tat /n;


//Display Result
printf("\n----------------------------------------\n");
printf("Process\tBurstTime\tWaitingTime\tTurnAroundTime\n");
printf("\n----------------------------------------\n");
for(i=0;i<n;i++){
printf("P%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
printf("------------------------------------------\n");
printf("Average waiting time =%.2f\n",avg_wt);
printf("Average Turnaround Time=%.2f\n",avg_tat);
return 0;
}

