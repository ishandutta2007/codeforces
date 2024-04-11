#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
bool bejar[5009];
int elhagy[5009];
vi G[5009];
vector<pii> ed;
int ido=0;
void dfs(int x)
{
    bejar[x]=true;
    for(int sz: G[x])
    {
        if(!bejar[sz]) dfs(sz);
    }
    ido++;
    elhagy[x]=ido;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        ed.push_back({a, b});
    }
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i]) dfs(i);
    }
    bool dag=true;
    for(pii p: ed)
    {
        if(elhagy[p.F]<elhagy[p.S])
        {
            dag=false;
            break;
        }
    }
    if(dag)
    {
        cout<<1<<endl;
        for(int i=1; i<=m; i++) cout<<1<<" ";
        cout<<endl;
    }
    else
    {
        cout<<2<<endl;
        for(pii p: ed)
        {
            if(p.F<p.S) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;
    }

    return 0;
}