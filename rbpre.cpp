#include<iostream>
using namespace std;
void swap(int *a, int *b) {
     int temp = *a;*a = *b; *b = temp;
     }
void rrpc() {
    int n, tq;
    cout << "Enter the total number of processes: "; cin >> n;
    cout << "Enter the value of time quantum: "; cin >> tq;
    int bt[n], p[n], at[n], rbt[n], pos;
    for (int i = 0; i < n; i++) {
         cout << "Enter the arrival time and burst time for P" << i + 1 << ": ";  cin >> at[i] >> bt[i];
        rbt[i] = bt[i];
        p[i] = i + 1; }
    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) 
            if (at[j] < at[pos])
                pos = j;
        swap(&at[i], &at[pos]);
        swap(&bt[i], &bt[pos]);
        swap(&rbt[i], &rbt[pos]);
        swap(&p[i], &p[pos]);
    }
    int wt[n], ct[n], queue[n] = {0};
    float avg = 0;
    bool complete[n] = {false};
    int timer = 0, maxprocess = 0;
    while (timer < at[0])
     timer++;
    queue[0] = 1;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++){
            if (rbt[i] != 0) {
                done = false;
                break; } }
        if (done)
            break;
        for (int i = 0; (i < n) && (queue[i] != 0); i++) {
            int ctr = 0;
            while ((ctr < tq) && (rbt[queue[0] - 1] > 0)) {
                rbt[queue[0] - 1] -= 1;
                timer++;
                ctr++;
                if (timer <= at[n - 1]) {
                    bool newArrival = false;
                    for (int j = (maxprocess + 1); j < n; j++) {
                        if (at[j] <= timer) {
                            if (maxprocess < j) {
                                maxprocess = j;
                                newArrival = true;  }  }   }
                    if (newArrival) {
                        for (int i = 0; i < n; i++) {
                            if (queue[i] == 0){
                                queue[i] = maxprocess + 1;
                                break; }
                        } }
                } }
            if ((rbt[queue[0] - 1] == 0) && (complete[queue[0] - 1] == false)) {
                ct[queue[0] - 1] = timer;
                complete[queue[0] - 1] = true;  }
            bool idle = true;
            if (queue[n - 1] == 0) {
                for (int i = 0; (i < n) && (queue[i] != 0); i++) {
                    if (complete[queue[i] - 1] == false) {
                        idle = false;
                        break;
                    }
                } } 
                else {
                idle = false; }
            if (idle)
                timer++;
            for (int i = 0; (i < n - 1) && (queue[i + 1] != 0); i++) {
                int temp = queue[i];
                queue[i] = queue[i + 1];
                queue[i + 1] = temp;
            }       }       }
     cout << "\nWaiting time:" <<  endl;
    for (int i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i] - bt[i];
         cout << "\nP" << p[i] << "\t" << wt[i] <<  endl;
        avg += wt[i]; }
     cout << "\nAverage Waiting time = " << avg / n <<  endl;
    float avgTAT = 0;
     cout << "\nTurnaround time:" <<  endl;
    for (int i = 0; i < n; i++) {
        int tat = bt[i] + wt[i];
         cout << "\nP" << p[i] << "\t" << tat <<  endl;
        avgTAT += tat; }
     cout << "\nAverage Turnaround time = " << avgTAT / n <<  endl;}
int main() {
    rrpc();
    return 0;
}
