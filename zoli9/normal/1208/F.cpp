#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int t[2000009];
pii idx[2000009];
int n;
int mbit;
pii comb(pii x, pii y)
{
    if(x.F>y.F) return {x.F, max(x.S, y.F)};
    else if(x.F<y.F) return {y.F, max(x.F, y.S)};
    else return {x.F, max(x.S, y.S)};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int maxi=0;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        idx[t[i]].S=idx[t[i]].F;
        idx[t[i]].F=i;
        maxi=max(maxi, t[i]);
    }
    int maxis=maxi;
    while(maxis>0)
    {
        mbit++;
        maxis/=2;
    }
    for(int i=maxi; i>=0; i--)
    {
        for(int j=0; j<mbit; j++)
        {
            if((i & (1<<j)) == 0)
            {
                int bovit=i+(1<<j);
                if(bovit>maxi) continue;
                idx[i]=comb(idx[i], idx[bovit]);
            }
        }
    }
    int ans=0;
    for(int i=1; i<=n-2; i++)
    {
        int extra=0;
        for(int j=mbit-1; j>=0; j--)
        {
            if((t[i] & (1<<j))>0) continue;
            if(idx[extra+(1<<j)].S>i)
            {
                extra+=(1<<j);
            }
        }
        ans=max(ans, t[i]|extra);
    }
    cout<<ans<<endl;
    return 0;
}