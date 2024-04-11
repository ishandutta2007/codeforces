#include <bits/stdc++.h>
using namespace std;
struct pont
{
    int az;
    long long tav;
    int tip;
    bool operator<(const pont & p) const
    {
        if(tav!=p.tav) return tav>p.tav;
        return tip>p.tip;
    }
};
pont x, y;
int n, m, k;
bool bejar[300009];
vector<int> G[300009];
vector<long long> suly[300009];
long long t[300009];
priority_queue<pont> q;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) t[i]=-1;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        long long c;
        cin>>a>>b>>c;
        G[a].push_back(b);
        G[b].push_back(a);
        suly[a].push_back(c);
        suly[b].push_back(c);
    }
    for(int i=1; i<=k; i++)
    {
        int a;
        long long c;
        cin>>a>>c;
        x.az=a;
        x.tav=c;
        x.tip=1;
        q.push(x);
    }
    x.az=1;
    x.tav=0;
    x.tip=0;
    q.push(x);
    while(q.size()>0)
    {
        x=q.top();
        q.pop();
        if(!bejar[x.az])
        {
            bejar[x.az]=true;
            if(x.tip==1) k--;
            for(int i=0; i<G[x.az].size(); i++)
            {
                int sz=G[x.az][i];
                if(!bejar[sz])
                {
                    if(t[sz]==-1 || x.tav+suly[x.az][i]<t[sz])
                    {
                        y.az=sz;
                        y.tav=x.tav+suly[x.az][i];
                        t[sz]=x.tav+suly[x.az][i];
                        y.tip=0;
                        q.push(y);
                    }
                }
            }
        }
    }
    cout<<k<<endl;
    return 0;
}