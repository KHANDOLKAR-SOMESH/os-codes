#include<iostream>
 #define max 50
using namespace std;
 
int main()
{
    int bt[max],p[max],wt[max],tat[max],pr[max],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    cout<<"Enter Total Number of Process:\n";
    cin>>n;
 
    cout<<"\nEnter Burst Time and Priority\n";
    for(i=0;i<n;i++)
    {
        
        cin>>bt[i];
        cin>>pr[i];
        p[i]=i+1;           
    }
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;          
 
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      
    total=0;
 
    cout<<"\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time";
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        cout<<"\n"<<p[i]<<"\t\t  "<<bt[i]<<"\t\t    "<<wt[i]<<"\t\t\t"<<tat[i];
    }
 
    avg_tat=total/n;     
    cout<<"\n\nAverage Waiting Time="<<(float)avg_wt+0.2;
    cout<<"\nAverage Turnaround Time="<<(float)avg_tat;
 
    return 0;
}