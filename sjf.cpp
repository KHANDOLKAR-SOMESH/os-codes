#include<iostream>
using namespace std;
class calculate
{
int n,pos;
public:calculate();
void swap(int *a,int *b){int temp; temp=*a;*a=*b;*b=temp;}
void cal_wt(int [],int []);
void cal_tat(int [],int []);
};
calculate::calculate()
{
cout<<"Enter the total number of processes"<<endl;
cin>>n;
int bt[n],p[n];
for(int i=0;i<=n-1;i++)
{
cin>>bt[i];
p[i]=i+1;
}
for(int i=0;i<n;i++)
 {
 pos=i;
 for(int j=i+1;j<n;j++)
 {
 if(bt[j]<bt[pos])
 pos=j;
 }
swap(&bt[i],&bt[pos]);
 swap(&p[i],&p[pos]);
 }
cal_wt(bt,p);
cal_tat(bt,p);
}
void calculate::cal_wt(int bt[],int p[])
{
int wait[n]={0};
float avg=0;
for(int i=1;i<n;i++)
{
wait[i]= wait[i-1]+bt[i-1];
}
cout<<"Waiting time"<<endl;
for(int i=0;i<=n-1;i++)
{
cout<<"\nP"<<p[i]<<"\t"<<"\t"<<wait[i]<<endl;
avg=wait[i]+avg;
}
cout<<"\nAverage Waiting time ="<<(float)avg/n<<endl;
}
void calculate::cal_tat(int bt[],int p[])
{
int wait[n]={0};
float avg=0;
wait[0] = bt[0];
for(int i=1;i<n;i++)
{
wait[i]= wait[i-1]+bt[i];
}
cout<<"Turn around time"<<endl;
for(int i=0;i<=n-1;i++)
{
cout<<"\nP"<<p[i]<<"\t"<<"\t"<<wait[i]<<endl;
avg=wait[i]+avg;
}
cout<<"\nAverage Turn around time ="<<(float)avg/n;
}
int main()
{
calculate a;
return 0;
}