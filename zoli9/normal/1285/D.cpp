#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n;
vll v;
int db[39];

ll solve(int x, int y, int kit)
{
    if(kit<0 || x==y) return 0;
    int z=-1;
    vll kk, nn;
    for(int i=x; i<=y; i++)
    {
        if(v[i]&(1LL<<(kit))) nn.push_back(v[i]);
        else kk.push_back(v[i]);
    }
    if(kk.size()==0 || nn.size()==0) return solve(x, y, kit-1);
    int u=x;
    for(ll w: kk) v[u++]=w;
    for(ll w: nn) v[u++]=w;
    int ks=kk.size();
    ll ret=min(solve(x, x+ks-1, kit-1), solve(x+ks, y, kit-1));
    ret+=(1LL<<kit);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cout<<solve(0, n-1, 29)<<endl;

    return 0;
}