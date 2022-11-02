#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
bool osszetett[10009];
int maxp=10000;
bool prim(int p)
{
    return !osszetett[p];
}
vector<pii> e;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=2; i<=maxp; i++)
    {
        if(osszetett[i]) continue;
        for(int j=2*i; j<=maxp; j+=i)
        {
            osszetett[j]=true;
        }
    }
    cin>>n;
    int elek=n;
    while(!prim(elek)) elek++;
    for(int i=1; i<n; i++) e.push_back({i, i+1});
    e.push_back({n, 1});
    for(int i=1; i<=elek-n; i++)
    {
        e.push_back({i, i+n/2});
    }
    cout<<e.size()<<endl;
    for(pii pp: e)
    {
        cout<<pp.first<<" "<<pp.second<<endl;
    }
    return 0;
}