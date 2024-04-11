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
    int q;
    vector<ll> v(3);
    cin>>q;
    for(int tt=1; tt<=q; tt++)
    {
        for(int i=0; i<3; i++) cin>>v[i];
        sort(v.begin(), v.end());
        if(v[0]==v[1] && v[0]==v[2])
        {
            cout<<0<<endl;
            continue;
        }
        if(v[0]==v[1])
        {
            cout<<max(0ll, v[2]+v[2]-v[1]-v[0]-4)<<endl;
            continue;
        }
        if(v[1]==v[2])
        {
            cout<<max(0ll, v[1]+v[2]-v[0]-v[0]-4)<<endl;
            continue;
        }
        v[2]--;
        v[0]++;
        cout<<v[2]-v[1]+v[2]-v[0]+v[1]-v[0]<<endl;
    }

    return 0;
}