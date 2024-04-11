#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
ll n, m;
ll sum[11];
bool was[10];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        for(int i=1; i<=10; i++) sum[i]=(m*i)%10;
        ll s=0;
        for(int i=1; i<=10; i++) s+=sum[i];
        ll hany=n/m;
        ll h2=hany/10;
        ll ans=0;
        for(int i=1; i<=hany%10; i++) ans+=sum[i];
        ans+=(h2*s);
        cout<<ans<<endl;
    }

    return 0;
}