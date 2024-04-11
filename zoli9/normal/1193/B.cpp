#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, k;
vi G[100009];
ll fruitw[100009];
int fruitd[100009];
map<int, ll> ma[100009];
int mid[100009];
void addfruit(int x)
{
    int ix=mid[x];
    if(fruitw[x]==0) return;
    ma[ix][fruitd[x]]+=fruitw[x];
    auto it=ma[ix].upper_bound(fruitd[x]);
    ll sumval=0;
    while(it!=ma[ix].end())
    {
        if(sumval+(it->S)>fruitw[x])
        {
            ma[ix][it->F]+=(sumval-fruitw[x]);
            return;
        }
        else
        {
            sumval+=(it->S);
            ma[ix].erase(it++);
        }
    }
}
void merging(int x, int y)
{
    auto yit=ma[y].begin();
    while(yit!=ma[y].end())
    {
        ma[x][yit->F]+=(yit->S);
        yit++;
    }
}
void dfs(int x)
{
    if(G[x].size()==0)
    {
        ma[mid[x]][0]=0;
        addfruit(x);
        return;
    }
    dfs(G[x][0]);
    mid[x]=mid[G[x][0]];
    for(int i=1; i<G[x].size(); i++)
    {
        dfs(G[x][i]);
        if(ma[mid[x]].size()<ma[mid[G[x][i]]].size())
        {
            merging(mid[G[x][i]], mid[x]);
            mid[x]=mid[G[x][i]];
        }
        else
        {
            merging(mid[x], mid[G[x][i]]);
        }
    }
    addfruit(x);
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    mid[1]=1;
    for(int i=2; i<=n; i++)
    {
        int dd;
        cin>>dd;
        G[dd].push_back(i);
        mid[i]=i;
    }
    for(int i=1; i<=m; i++)
    {
        int vv;
        int dd;
        ll ww;
        cin>>vv>>dd>>ww;
        fruitd[vv]=dd;
        fruitw[vv]=ww;
    }
    dfs(1);
    auto ansit=ma[mid[1]].begin();
    ll ans=0;
    while(ansit!=ma[mid[1]].end())
    {
        ans+=(ansit->S);
        ansit++;
    }
    cout<<ans<<'\n';
    return 0;
}