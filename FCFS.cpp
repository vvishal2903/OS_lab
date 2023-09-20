#include<iostream>
#include<stdlib.h>
using namespace std;
//class process with all the time values and functions
class Process{
    int id, bt, at, ct, tat, wt;
    public:
    void input(Process*,int );
    void calc(Process *,int);
    void show(Process*,int);
    void sort(Process *, int);
};
//main function
int main(){
    int n;
    cout<<"\nEnter the no of processes in your system:\n";
    cin>>n;
    Process *p = new Process[n];
    Process f;
    f.input(p,n);
    f.sort(p, n);
    f.calc(p,n);
    f.show(p,n);
    return 0;
}
//taking input arrival and burst times for all processes
void Process::input(Process *p,int n){
    for(int i = 0;i<n;i++){
        cout<<"\nEnter pival time for process "<<i+1<<":\n";
        cin>>p[i].at;
        cout<<"\nEnter burst time for process "<<i+1<<":\n";
        cin>>p[i].bt;
        p[i].id = i+1;
    }
}
//calculating waiting, turn-around and completion time
void Process::calc(Process*p, int n){
    int sum = 0;
    sum = sum + p[0].at;
    for(int i = 0;i<n;i++){
        sum = sum + p[i].bt;
        p[i].ct = sum;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;  
        if(sum<p[i+1].at){
            int t = p[i+1].at-sum;
            sum = sum+t;
        } 
    }
}
//Sorting processes with respect to arrival times (needed for synchronized input)
void Process::sort(Process*p, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].at>p[j+1].at){
                int temp;
                //sorting burst times
                temp = p[j].bt;
                p[j].bt = p[j+1].bt;
                p[j+1].bt = temp;
                //sorting arrival times
                temp = p[j].at;
                p[j].at = p[j+1].at;
                p[j+1].at = temp;
                //sorting their respective IDs
                temp = p[j].id;
                p[j].id = p[j+1].id;
                p[j+1].id = temp;
            }
        }
    }
}
//display function
void Process::show(Process*p, int n){
    cout<<"Process\tArrival\tBurst\tWaiting\tTurn Around\tCompletion\n";
    for(int i =0;i<n;i++){
        cout<<"  P["<<p[i].id<<"]\t  "<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].wt<<"\t   "<<p[i].tat<<"\t\t"<<p[i].ct<<"\n";
    }
}
Output: 

Processes  Burst Time  Arrival Time  Waiting Time  Turn-Around Time  Completion Time 
 1        5        0        0         5         5
 2        9        3        2         11         14
 3        6        6        8         14         20
Average waiting time = 3.33333
Average turn around time = 10.0
Example2:

#include<iostream>
using namespace std;
  
int main()
{
    int n, burst_time[20], waiting_time[20], turnaround_time[20];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
  
    cout<<"Enter total number of processes(maximum 20): ";
    cin>>n;
  
    cout<<"\nEnter Process Burst Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]: ";
        cin>>burst_time[i];
    }
  
    waiting_time[0] = 0; // Waiting time for first process is 0
  
    // Calculating waiting time
    for(int i=1;i<n;i++)
    {
        waiting_time[i] = 0;
        for(int j=0;j<i;j++)
        {
            waiting_time[i] += burst_time[j];
        }
    }
  
    // Calculating turnaround time by adding burst_time and waiting_time
    for(int i=0;i<n;i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
  
    avg_turnaround_time /= n;
    cout<<"\nAverage Turnaround Time: "<<avg_turnaround_time<<"ms\n";
  
    // Calculating average waiting time
    for(int i=0;i<n;i++)
    {
        avg_waiting_time += waiting_time[i];
    }
  
    avg_waiting_time /= n;
    cout<<"\nAverage Waiting Time: "<<avg_waiting_time<<"ms\n\n";
  
    cout<<"Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turnaround_time[i]<<endl;
    }
  
    return 0;
}