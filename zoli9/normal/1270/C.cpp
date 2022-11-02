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
int test;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        ll sum=0;
        ll x=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            ll sss;
            cin>>sss;
            sum+=sss;
            x^=sss;
        }
        cout<<3<<endl;
        cout<<x<<" ";
        sum+=x;
        ll kicsi=(1ll<<(50));
        ll nagy=(1ll<<(50))+(1ll<<(51))+sum;
        cout<<kicsi<<" "<<nagy<<endl;
    }
    return 0;
}