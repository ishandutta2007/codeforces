#include <iostream>
using namespace std;
typedef long long ll;
#define fi for(int i=1; i<=n; i++)
ll n;
ll t[109];
ll maxi=-1;
ll oszto;
ll lnko(ll a, ll b)
{
    ll m;
    do {
        m = a % b;
        a = b;
        b = m;
    } while (m != 0);
    return a;
}
int main()
{
    cin>>n;
    fi
    {
        cin>>t[i];
        maxi=max(maxi, t[i]);
    }
    oszto=t[1];
    fi
    {
        oszto=lnko(oszto, t[i]);
    }
    ll g=maxi/oszto;
    if((g-n)%2) cout<<"Alice";
    else cout<<"Bob";
    return 0;
}