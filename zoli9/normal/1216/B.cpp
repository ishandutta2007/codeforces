#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
vector<pair<ll, int> > v;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        ll szam;
        cin>>szam;
        v.push_back({szam, i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        ans+=((i*v[i].F)+1);
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<v[i].S<<" ";
    }
    cout<<endl;

    return 0;
}