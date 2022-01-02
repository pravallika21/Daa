# include<stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity)
{
float x[20],pr=0;
int i,j,u;
u=capacity;
for(i=0;i<n;i++)
x[i]=0.0;
for(i=0;i<n;i++)
{
if(weight[i]>u)
break;
else
{
x[i]=1.0;
pr=pr+profit[i];
u=u-weight[i];
}
}

if(i<n)
x[i]=u/weight[i];
pr=pr+(x[i]*profit[i]);
printf("\n Result array x is...");
for(i=0;i<n;i++)
printf("%f\t",x[i]);
printf("\n Profit is..... %f",pr);
}
void main()
{
float weight[20],profit[20],capacity;
int n,i,j;
float ratio[20],t;
printf("\n enter the capacityacity of knapsack...");
scanf("%f",&capacity);
printf("\n Toal no of objects...");
scanf("%d",&n);
printf("\n Enter the weights and profits of each object...");
for (i=0;i<n;i++)
{
scanf("%f %f",&weight[i],&profit[i]);
}
for (i=0;i<n;i++)
{
ratio[i]=profit[i]/weight[i];
}
for (i=0;i<n;i++)
{
for (j=i + 1;j<n;j++)
{
if (ratio[i]<ratio[j])
{
t=ratio[j];
ratio[j]=ratio[i];
ratio[i]=t;
t=weight[j];
weight[j]=weight[i];
weight[i]=t;
t=profit[j];

profit[j]=profit[i];
profit[i]=t;
}
}
}
knapsack(n,weight,profit,capacity);
}
