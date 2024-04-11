#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
ll t[200009];
ll maxi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        maxi=max(maxi, t[i]);
    }
    if(maxi==0)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    ll gcd=-1;
    for(int i=1; i<=n; i++)
    {
        if(t[i]<maxi)
        {
            if(gcd==-1) gcd=maxi-t[i];
            else gcd=__gcd(gcd, maxi-t[i]);
        }
    }
    if(gcd==-1)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(t[i]!=maxi)
        {
            ans+=((maxi-t[i])/gcd);
        }
    }
    cout<<ans<<" "<<gcd<<endl;


    return 0;
}