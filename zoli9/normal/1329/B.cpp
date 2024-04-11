#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll d, m;
        cin>>d>>m;
        ll x=1;
        ll ans=1;
        while(2*x<=d)
        {
          ans=(ans*(x+1))%m;
          x*=2;
        }
        ll utolso=d-x+1;
        ans=(ans*(utolso+1))%m;
        ans=(ans-1+m)%m;
        cout<<ans<<'\n';
    }


    return 0;
}