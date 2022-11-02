#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll m;
vector<ll> t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    t.resize(m);
    for(ll i=0; i<m; i++)
    {
        cin>>t[i];
    }
    ll cnt=0;
    int ans=0;
    while(cnt<m)
    {
        ll eddig=cnt;
        ll idx=t[cnt]-cnt;
        ll pagestart=idx-idx%k;
        if(idx%k==0) pagestart-=k;
        while(cnt<m && pagestart+k>=t[cnt]-eddig) cnt++;
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}