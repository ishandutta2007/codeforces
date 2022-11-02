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
ll n, test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        ll sum=0;
        for(int i=1; i<=n; i++)
        {
            ll szam;
            cin>>szam;
            sum+=szam;
        }
        if(sum%n==0) cout<<(sum/n)<<endl;
        else cout<<(sum/n+1)<<endl;
    }

    return 0;
}