#include<iostream>
using namespace std;
class case2
{
	int n;
	public:
	case2(){
	cout<<"Enter the total number of processes"<<endl;
	cin>>n;
	int bt[n],at[n];
	cout<<"Enter the value of arrival time for process "<<endl;
	for(int i=0;i<=n-1;i++)
	{
		
		cin>>at[i];
	}
	cout<<"Enter the value of burst time for process "<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cin>>bt[i];
	}
	wt(at,bt);	
}
	void wt(int [],int []);
	void trt(int [],int []);
};

void case2::wt(int at[],int bt[])
{
	int twait[n]={0},et[n]={0};
	float avg=0;
	twait[0]=at[0];
	et[0]=at[0];
	for(int i=1;i<=n;i++)
	{
		et[i]=et[i-1]+bt[i-1];	
	}
	for(int i=0;i<=n-1;i++)
	{
		twait[i]= et[i] - at[i];	
	}
	cout<<"Waiting time"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"\nP"<<i+1<<"\t"<<twait[i]<<endl;
		avg=twait[i]+avg;
	}
	cout<<"\nAverage Waiting time ="<<(float)avg/n<<endl;
	trt(twait,bt);
}

void case2::trt(int twait[],int bt[])
{
	int wait[n]={0};
	float avg=0;
	for(int i=0;i<=n-1;i++)
		wait[i]=twait[i]+bt[i];
	cout<<"Turn around time"<<endl;
	for(int i=0;i<=n-1;i++)
	{
		cout<<"\nP"<<i+1<<"\t"<<wait[i]<<endl;
		avg=wait[i]+avg;
	}
	cout<<"\nAverage Turn around time ="<<(float)avg/n;
}
int main()
{
	case2 x;
	return 0;
}
