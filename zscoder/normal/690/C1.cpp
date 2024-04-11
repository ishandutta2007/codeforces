#include <bits/stdc++.h>
using namespace std;

int par[100001];

int rt(int u)
{
    if(par[u] == -1) return u;
    else return (par[u] = rt(par[u]));
}

bool merge(int u, int v)
{
    u = rt(u); v = rt(v);
    if(u == v) return true;
    if(rand()&1) swap(u, v);
    par[u] = v;
    return false;
}
int main()
{
    int n; cin >> n;
    int m; cin >> m;
    srand(1947131);
    if(m != n-1)
    {
        cout << "no"; return 0;
    }
    memset(par,-1,sizeof(par));
    for(int i = 0; i < m; i++)
    {
        int u, v; cin>>u>>v; u--; v--;
        if(merge(u,v))
        {
            cout<<"no"; return 0;
        }
    }
    cout<<"yes";
}