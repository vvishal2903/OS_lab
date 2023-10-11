#include <iostream>

using namespace std;

class Process {
public:
    int id;
    int burstTime;
    int remainingTime;
    Process(){};
    Process(int _id, int _burstTime) : id(_id), burstTime(_burstTime), remainingTime(_burstTime) {}
};

void roundRobin(Process processes[], int numProcesses, int quantum) {
    int currentTime = 0;
    int front = 0, rear = 0;
    int queue[numProcesses]; // Circular queue to simulate readyQueue

    while (true) {
        bool found = false;

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].burstTime > 0 && processes[i].burstTime <= quantum) {
                currentTime += processes[i].burstTime;
                processes[i].burstTime = 0;
                cout << "Executing Process " << processes[i].id << " for " << processes[i].burstTime << " units. Process " << processes[i].id << " completed." << endl;
            } else if (processes[i].burstTime > 0) {
                processes[i].burstTime -= quantum;
                currentTime += quantum;
                cout << "Executing Process " << processes[i].id << " for " << quantum << " units. ";
            }

            while (front != rear && queue[front] == i)
                front = (front + 1) % numProcesses;

            for (int j = 0; j < numProcesses; j++) {
                if (processes[j].burstTime > 0 && processes[j].burstTime <= currentTime) {
                    queue[rear] = j;
                    rear = (rear + 1) % numProcesses;
                    found = true;
                }
            }

            if (found)
                break;
        }

        if (!found)
            break;
    }
}

int main() {
    int numProcesses, quantum;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    Process processes[numProcesses];

    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter burst time for Process " << i << ": ";
        int burstTime;
        cin >> burstTime;
        processes[i] = Process(i, burstTime);
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    cout << "Round Robin Scheduling:" << endl;
    roundRobin(processes, numProcesses, quantum);

    return 0;
}
