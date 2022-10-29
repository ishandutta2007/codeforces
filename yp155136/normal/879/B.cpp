#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    long long k;
    cin >> n >>k;
    deque<int> dq;
    for (int i=1;n>=i;i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int cnt=0;
    while (true)
    {
        if (cnt == k) break;
        if (dq.front() == n) break;
        int a=dq[0],b=dq[1];
        if (a>b)
        {
            dq.pop_front();
            dq.pop_front();
            dq.push_front(a);
            dq.push_back(b);
            cnt++;
        }
        else
        {
            dq.pop_front();
            dq.push_back(a);
            cnt=1;
        }
    }
    cout <<dq.front()<<endl;
}