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
ll a[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    int n;
    ll sum;
    ll s;
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>s;
        sum=0;
        int maxp=1;
        ll maxi=0;
        for(int i=1; i<=n; i++) cin>>a[i];
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            sum+=a[i];
            if(a[i]>maxi)
            {
                maxi=a[i];
                maxp=i;
            }
            if(sum>s)
            {
                ans=maxp;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}