#include<iostream>
using namespace std;

int main()
{
    int allocation[5][3], max[5][3], need[5][3], total[1][3], available[1][3];
    cout << "Enter allocated resources:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "P" << i << ":" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "R" << j << ": ";
            cin >> allocation[i][j];
        }
    }

    cout << "Enter maximum resources:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "P" << i << ":" << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "R" << j << ": ";
            cin >> max[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    cout << "Enter total number of resources:" << endl;
    for (int j = 0; j < 3; j++)
    {
        cin >> total[0][j];
    }

    cout << "Enter currently available resources:" << endl;
    for (int j = 0; j < 3; j++)
    {
        cin >> available[0][j];
    }

    bool finish[5] = {false, false, false, false, false};
    int work[3];

    for (int j = 0; j < 3; j++)
    {
        work[j] = available[0][j];
    }

    int safeSequence[5];
    int count = 0;

    while (count < 5)
    {
        bool found = false;
        for (int i = 0; i < 5; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < 3; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count] = i;
                    count++;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        if (!found)
        {
            cout << "System is in an unsafe state!" << endl;
            break;
        }
    }

    if (count == 5)
    {
        cout << "System is in a safe state. Safe sequence: ";
        for (int i = 0; i < 5; i++)
        {
            cout << "P" << safeSequence[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
