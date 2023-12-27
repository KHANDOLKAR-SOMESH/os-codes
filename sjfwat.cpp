#include <iostream>
#include <stdlib.h>
#define max 30

using namespace std;

void input(int bt[],int process[],int at[],int n)
{
  cout<<"Enter burst time and arrival time for  processes : "<<endl;
  for(int i=0;i<n;i++)
 
  {
    process[i]=i;
    cin>>bt[i];
    cin>>at[i];
   
  }
}
void sort_at(int at[],int process[],int bt[],int n)
{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(at[i]>at[j])
      {
        swap(process[i],process[j]);
        swap(at[i],at[j]);
        swap(bt[i],bt[j]);
      }
    }
  }
}

void sort_bt(int at[],int process[],int bt[],int n)

{
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(at[i]==at[j])
      
      {
        if(bt[i]>bt[j])
       
        {
          swap(process[i],process[j]);
          swap(at[i],at[j]);
          swap(bt[i],bt[j]);
        }
      }
    }
  }
}

void sjf_operations(int at[],int wt[],int bt[],int tat[],int ct[],int n)

{
  int temp;
  int value;

  ct[0] = at[0] + bt[0];
  tat[0] = ct[0] - at[0];
  wt[0] = tat[0] - bt[0];


  for(int i=1;i<4;i++)

  {
    temp = ct[i-1];
    int low = bt[i];
    for(int j=i;j<n;j++)
    {
      if(temp >= at[j] && low >=bt[j])
      
        low = bt[j];
        value = j;
      }
    }
    ct[value] = temp + bt[value];
    tat[value] = ct[value] - at[value];
    wt[value] = tat[value] - bt[value];
   
}

void print_table(int process[],int bt[],int wt[],int tat[],int at[],int n)

{
  cout<<endl<<endl;

  cout<<"Process"<<" \t"<<"Arrival Time"<<" \t"<<"Burst Time"<<" \t"<<"Waiting Time"<<" \t"<<"Turn Around Time"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<process[i]<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
  }

  cout<<endl<<endl;
}

int main()
{int n;
  int process[max], bt[max], wt[max], ct[max], tat[max], at[max];
  cout<<"enter total no of processes";
   cin>>n;

  input(bt,process,at,n);

  sort_at(at,process,bt,n);

  sort_bt(at,process,bt,n);

  sjf_operations(at,wt,bt,tat,ct,n);

  print_table(process,bt,wt,tat,at,n);
  int r=0,s=0;
  for (int i = 0; i <n; i++)
  {
    s+=wt[i];
    r+=tat[i];
  }
  cout<<"awt"<<s/n<<"  "<<"atat"<<r/n;
  

  return 0;
}
