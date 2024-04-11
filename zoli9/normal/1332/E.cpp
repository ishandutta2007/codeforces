#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll MOD=998244353;
ll inv2=499122177;
ll powmod(ll b, ll e)
{
    b%=MOD;
    ll res=1;
    while(e>0)
    {
        if(e%2)
        {
            res=(res*b)%MOD;
        }
        b=(b*b)%MOD;
        e/=2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m, L, R;
    cin>>n>>m>>L>>R;
    ll d=R-L+1;
    ll dtonm=powmod(d, n*m);
    if(n%2 && m%2)
    {
        cout<<dtonm<<endl;
        return 0;
    }
    if(d%2==0)
    {
        cout<<(dtonm*inv2)%MOD<<endl;
        return 0;
    }
    dtonm=(dtonm+1)%MOD;
    cout<<(dtonm*inv2)%MOD<<endl;
    return 0;
}