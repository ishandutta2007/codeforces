#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int test;
int n;
ll x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>x;
        ll maxi=0;
        bool jo=false;
        for(int i=1; i<=n; i++)
        {
            ll mmm;
            cin>>mmm;
            maxi=max(maxi, mmm);
            if(mmm==x) jo=true;
        }
        if(jo)
        {
            cout<<1<<endl;
            continue;
        }
        if(maxi>x)
        {
            cout<<2<<endl;
            continue;
        }
        ll ans=x/maxi;
        if(x%maxi!=0) ans++;
        cout<<ans<<endl;
    }


    return 0;
}