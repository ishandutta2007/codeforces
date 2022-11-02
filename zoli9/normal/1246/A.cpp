#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
ll n, p;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>p;
    for(ll ans=1; ans<=1000; ans++)
    {
        ll kell=n-ans*p;
        if(kell<ans) continue;
        ll bitek=0;
        while(kell>0)
        {
            if(kell%2) bitek++;
            kell/=2;
        }
        if(ans>=bitek)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}