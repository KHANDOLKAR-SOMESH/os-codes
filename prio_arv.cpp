#include <iostream>
using namespace std;
int main()
{
    int n ; //number of processes to be scheduled
    int at[10] ;
    int bt[9] ;
    int priority[8];
    int x[9];
cout<<"Enter Total Number of Process:\n";
    cin>>n;
     cout<<"\nEnter Burst Time and Priority\n";
    for(int i=0;i<n;i++)
    {
        
        cin>>at[i];
        cin>>bt[i];
       cin>> priority[i];           
    }

    int wt[n], tat[n];
    int i, j, sm, count = 0, time; // count -> number of processes completed
    double avg = 0, tt = 0, end;


    for (i = 0; i < n; i++)
        x[i] = bt[i];


    priority[n] = 10000;


    for (time = 0; count != n; time++)
    {
        sm = n;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && priority[i] < priority[sm] && bt[i] > 0)
                sm = i;
        }
        bt[sm]--;
        if (bt[sm] == 0)
        {
            count++;
            end = time + 1;
            wt[sm] = end - at[sm] - x[sm];
            tat[sm] = end - at[sm];
        }
    }
    cout << "Process"<< "\t  "<< "burst-time" << "\t "<< "arrival-time"<< "\t "<< "waiting-time"<< "\t"<< "turnaround-time"<< "\t "<< "\t"<< "Priority" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tat[i]  << "\t\t" << priority[i] << endl;
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout << "\n\nAverage waiting time time = " << avg / n;
    cout << "  Average turnaround time time = " << tt / n << endl;
}