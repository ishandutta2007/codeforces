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
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        ll k;
        cin>>n>>k;
        vll a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        ll mini=a[0]+k;
        ll maxi=a[0]+k;
        bool ok=true;
        for(ll i=1; i<n-1; i++)
        {
            if(a[i]>=maxi)
            {
                ok=false;
                break;
            }
            if(mini-k>=a[i]+k-1+k)
            {
                ok=false;
                break;
            }
            maxi=min(maxi+k-1, a[i]+k-1+k);
            mini=max(mini-k+1, a[i]+k);
        }
        if(a[n-1]+k<=mini-k) ok=false;
        if(a[n-1]>=maxi) ok=false;
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}