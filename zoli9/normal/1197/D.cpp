#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
ll n, m, k;
ll t[300009];
ll b[300009];
ll kum[300009];
ll getsum(int x, int y)
{
    if(x<=0) return kum[y];
    return kum[y]-kum[x-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        kum[i]=kum[i-1]+t[i];
    }
    ll ans=0;
    for(int l=1; l<=m && l<=n; l++)
    {
        ans=max(ans, getsum(1, l)-k);
    }
    //cout<<ans<<endl;

    for(int i=1; i<=n; i++)
    {
        if(i>=m)
        {
            ll nb=getsum(i-m+1, i)-k;
            if(i-m>=1) nb+=b[i-m];
            b[i]=max(b[i], nb);
        }
        for(int l=0; l<m && i+l<=n; l++)
        {
            ans=max(ans, b[i]+getsum(i+1, i+l)-k*(l>0));
        }
    }


    cout<<ans<<endl;

    return 0;
}