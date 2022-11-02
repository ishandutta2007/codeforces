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
    ll n;
    cin>>n;
    vll a(3);
    vll b(3);
    for(int i=0; i<3; i++) cin>>a[i];
    for(int i=0; i<3; i++) cin>>b[i];
    ll maxi=0;
    for(int i=0; i<3; i++)
    {
        maxi+=(min(a[i], b[(i+1)%3]));
    }
    ll mini=0;
    for(int i=0; i<3; i++)
    {
        mini=max(mini, a[i]-b[i]-b[(i+2)%3]);
    }
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}