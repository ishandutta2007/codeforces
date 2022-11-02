#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int m[3000009];
int a[300009];
int ans[300009];
int n, test;
vpii Q[300009];

void add(int cs, int k, int v, int x, int d)
{
    if(x<k || v<x) return;
    m[cs]+=d;
    if(k==v) return;
    add(2*cs, k, (k+v)/2, x, d);
    add(2*cs+1, (k+v)/2+1, v, x, d);
}

int ask(int cs, int k, int v, int x, int y)
{
    if(v<x || y<k) return 0;
    if(x<=k && v<=y) return m[cs];
    return ask(2*cs, k, (k+v)/2, x, y)+ask(2*cs+1, (k+v)/2+1, v, x, y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>test;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    for(int i=1; i<=test; i++)
    {
        int x, y;
        cin>>x>>y;
        Q[n-y].push_back({x, i});
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]==i)
        {
            add(1, 0, n-1, i-1, 1);
        }
        else if(a[i]<i)
        {
            int needed=i-a[i];
            int p1=0;
            int p2=i-2;
            while(p1<=p2)
            {
                int mid=(p1+p2)/2;
                if(ask(1, 0, n-1, mid, i-1)>=needed) p1=mid+1;
                else p2=mid-1;
            }
            if(p2>=0)
            {
                add(1, 0, n-1, p2, 1);
            }
        }
        for(int j=0; j<Q[i].size(); j++)
        {
            ans[Q[i][j].S]=ask(1, 0, n-1, Q[i][j].F, n-1);
        }
    }
    for(int i=1; i<=test; i++)
    {
        cout<<ans[i]<<'\n';
    }
    return 0;
}