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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    ll r, g, b;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>r>>g>>b;
        if(r+g>=b-1 && r+b>=g-1 && b+g>=r-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}