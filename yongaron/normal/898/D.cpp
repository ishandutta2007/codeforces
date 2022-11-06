#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<int> t;
queue<int> q;

int main()
{
    cin>>n>>m>>k;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        t.push_back(a);
    }
    sort(t.begin(), t.end());
    int al = 0;
    for(int i = 0; i < n; i++)
    {
        int time = t[i];
        while(!q.empty() && (q.front() <= time-m))
            q.pop();
        if(q.size() == k-1)
            al++;
        else
            q.push(time);
    }
    cout<<al<<endl;
    return 0;
}