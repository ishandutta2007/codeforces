#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, z;
    cin>>x>>y>>z;
    if(x/z+y/z==(x+y)/z)
    {
        cout<<((x+y)/z)<<" "<<0<<endl;
        return 0;
    }
    ll xx=x%z;
    if(xx>0) xx=z-xx;

    ll yy=y%z;
    if(yy>0) yy=z-yy;
    ll mini=min(xx, yy);
    cout<<((x+y)/z)<<" "<<mini<<endl;


    return 0;
}