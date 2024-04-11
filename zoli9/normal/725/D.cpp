#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n;
long long kapacitas;
vector<pair<pair<long long, int>, long long> >t;
int vecind;
int bestpoz;
priority_queue<long long> q;
int main()
{
    cin>>n;
    bestpoz=n+1;
    for(int i=1; i<=n; i++)
    {
        long long a, b;
        cin>>a>>b;
        t.push_back(make_pair(make_pair(a, -i), b));
        if(i==1) kapacitas=a;
    }
    sort(t.begin(), t.end());
    vecind=n-1;
    while(t[vecind].F.S!=(-1))
    {
        q.push(-(t[vecind].S-t[vecind].F.F));
        vecind--;
    }
    vecind--;
    while(1)
    {
        int qs=q.size();
        bestpoz=min(bestpoz, qs+1);
        if(q.size()==0)
        {
            cout<<1<<endl;
            return 0;
        }
        long long s=q.top();
        if(kapacitas>(-s))
        {
            q.pop();
            kapacitas+=s;
            kapacitas--;
        }
        else break;
        while(vecind>=0 && t[vecind].F.F>kapacitas)
        {
            q.push(-(t[vecind].S-t[vecind].F.F));
            vecind--;
        }
    }
    cout<<bestpoz<<endl;
    return 0;
}