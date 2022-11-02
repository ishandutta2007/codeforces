#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll MOD=1000000007;
ll fib[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, m;
    cin>>n>>m;
    fib[0]=0;
    fib[1]=1;
    for(int i=2; i<=100005; i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
    }
    ll ans=(2*fib[n+1]+2*fib[m+1])%MOD;
    ans=(ans-2+MOD)%MOD;
    cout<<ans<<endl;


    return 0;
}