#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    priority_queue<int> pq;
    long long tot=0;
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        tot += x;
    }
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        pq.push(x);
    }
    tot -= pq.top();
    pq.pop();
    tot -= pq.top();
    pq.pop();
    if (tot <= 0) puts("YES");
    else puts("NO");
}