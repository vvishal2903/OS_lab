#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Process {
    int id;            // Process ID
    int arrivalTime;   // Arrival time
    int burstTime;     // Burst time
    int remainingTime; // Remaining burst time

    Process(int id, int arrivalTime, int burstTime)
        : id(id), arrivalTime(arrivalTime), burstTime(burstTime), remainingTime(burstTime) {}

    bool operator<(const Process& other) const {
        return remainingTime > other.remainingTime;
    }
};

void SRTF(vector<Process>& processes) {
    priority_queue<Process> pq; // Min-heap based on remaining time
    int currentTime = 0;

    cout << "SRTF Scheduling:\n";

    while (!processes.empty() || !pq.empty()) {
        // Add arriving processes to the queue
        while (!processes.empty() && processes[0].arrivalTime <= currentTime) {
            pq.push(processes[0]);
            processes.erase(processes.begin());
        }

        if (!pq.empty()) {
            Process currentProcess = pq.top();
            pq.pop();

            cout << "Executing Process " << currentProcess.id << " at time " << currentTime
                 << " (Remaining Time: " << currentProcess.remainingTime << ")\n";

            currentTime += 1; // Execute for one time unit
            currentProcess.remainingTime -= 1;

            if (currentProcess.remainingTime > 0) {
                pq.push(currentProcess); // Re-add the process to the queue if it's not finished
            } else {
                cout << "Process " << currentProcess.id << " completed.\n";
            }
        } else {
            currentTime++; // No process to execute, just increment time
        }
    }
}

int main() {
    vector<Process> processes = {
        Process(1, 0, 6),
        Process(2, 1, 8),
        Process(3, 2, 7),
        Process(4, 3, 3)
    };

    SRTF(processes);

    return 0;
}