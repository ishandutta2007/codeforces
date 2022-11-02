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
        ll w, h, n;
        cin>>w>>h>>n;
        ll ans=1;
        while(h%2==0)
        {
            h/=2;
            ans*=2;
        }
        while(w%2==0)
        {
            w/=2;
            ans*=2;
        }
        if(ans>=n) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}