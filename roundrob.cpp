#include<iostream> 
using namespace std; 
class rr
{
	int n,quantum;
	public: rr(){
	cout<<"Enter the total number of processes"<<endl;
	cin>>n;
	cout<<"Enter the value of time quantum"<<endl;
	cin>>quantum;
	int bt[n],p[n];
    cout<<"Enter the burst time for p";
	for(int i=0;i<=n-1;i++)
	{
		
		cin>>bt[i];
		p[i]=i+1;
	}
	waitt(bt,p);}
			void waitt(int [],int []);
			void trunt(int [],int [],int []);
	
};
void rr::waitt(int bt[], int p[]){ 
	int rem_bt[n],wt[n];
	float avg=0; 
	for (int i=0;i<n;i++) 
		rem_bt[i]=bt[i]; 

	int t = 0; 
	while (true) { 
		bool done = true; 
		for (int i=0;i<n;i++) { 
			if (rem_bt[i]>0) { 
				done = false;
				if (rem_bt[i]>quantum) { 
					t=t+quantum; 
					rem_bt[i] = rem_bt[i] - quantum; 
				} 
				else{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; }        }           } 
		if (done == true) {break; }
	}
	cout<<"\nWaiting time"<<endl;
	for (int i=0; i<=n-1; i++) { 
		cout<<"\nP"<<p[i]<<"\t"<<wt[i]<<endl;
		avg=wt[i]+avg;
	}
	cout<<"\nAverage Waiting time ="<<(float)avg/n<<endl;
	trunt(bt,wt,p);
} 

void rr::trunt(int bt[],int wt[],int p[])
{ 
	int tat[n];
	float avg=0;
	cout<<"\nTurn around time"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		tat[i] = bt[i] + wt[i]; 
		cout<<"\nP"<<p[i]<<"\t"<<tat[i]<<endl;
		avg=tat[i]+avg;
	}
	cout<<"\nAverage Turn around time ="<<(float)avg/n;
} 
int main() { 	
	rr s1;
	return 0; 
}
