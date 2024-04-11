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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
        int n, m;
        cin>>n>>m;
        vll a(n);
        vll b(m);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<m; i++) cin>>b[i];
        ll G=-1;
        for(int i=1; i<n; i++)
        {
            ll x=abs(a[i]-a[i-1]);
            if(G==-1) G=x;
            else G=__gcd(G, x);
        }
        for(int i=0; i<m; i++)
        {
            if(G==-1)
            {
                cout<<a[0]+b[i]<<" ";
            }
            else
            {
                cout<<(__gcd(G, a[0]+b[i]))<<" ";
            }
        }
        cout<<'\n';

    return 0;
}