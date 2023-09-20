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