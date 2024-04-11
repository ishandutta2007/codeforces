#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        ll ans=0;
        ll a=1;
        ll b=1;
        while(b<=n)
        {
            ans++;
            a*=2;
            a++;
            ll pl=(a*(a+1))/2;
            b+=pl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}