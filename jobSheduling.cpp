#include <iostream>
#include <algorithm>
using namespace std;

class Job
{
public:
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit)
    {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

// Comparator function for sorting jobs by profit
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    Job jobs[] = {
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15)};

    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Sort jobs according to profit
    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    char result[maxDeadline];
    bool slot[maxDeadline];

    // Initialize slots
    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = false;
        result[i] = '-';
    }

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (result[i] != '-')
            cout << result[i] << " ";
    }

    cout << "\nTotal Profit: " << totalProfit << endl;

    return 0;
}