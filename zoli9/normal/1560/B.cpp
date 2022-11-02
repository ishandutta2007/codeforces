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

bool g(int x)
{
    if(x%3==0 || x%10==3) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll a, b, c;
        cin>>a>>b>>c;
        if(a>b) swap(a, b);
        ll k=b-a;
        if(a<=k && c<=2*k)
        {
            ll ans=c+k;
            if(c>k) ans=c-k;
            cout<<ans<<'\n';
            continue;
        }
        cout<<-1<<'\n';
    }
    return 0;
}