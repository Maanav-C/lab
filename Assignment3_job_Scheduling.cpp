#include<bits/stdc++.h>
using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};


bool compare(const Job &a, const Job &b)
{
    return a.profit>b.profit;
}

void schedule(const vector<Job> &jobs)
{
    int n = jobs.size();
    vector<bool> slots(n, false);
    vector<int> result(n, -1);

    for(int i=0; i<n; i++)
    {
        for(int j=min(n, jobs[i].deadline)-1; j>=0; j--)
        {
            if (!slots[j])
            {
                result[j] = i;
                slots[j] = true;
                break;
            }
        }
    }
    cout<<"Job Sequence: ";
    for(int i=0; i<n; i++)
    {
        if (result[i] != -1)
        {
            cout<<jobs[result[i]].id<<" ";
        }
    }
    cout<<endl;

    int totalprofit = 0;
    for(int i=0; i<n; i++)
    {
        if (result[i] != -1)
        {
            totalprofit += jobs[result[i]].profit;
        }
    }
    cout<<"Total profit is "<<totalprofit<<endl;
}

vector<int> selectionSort(vector<int> a)
{
    int n=a.size();
    for(int i=0; i<n; i++)
    {
        int min_idx=i;
        for(int j=i+1; j<n; j++)
        {
            if (a[j]<a[min_idx])
            {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
    return a;
}

int main()
{
    int n;
    cout<<"Enter the number of jobs";
    cin>>n;

    vector<Job> jobs(n);
    cout<<"Enter the job details (id, deadline, profit) for each job.\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Job "<<i+1<<": ";
        cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);
    schedule(jobs);

    return 0;
}