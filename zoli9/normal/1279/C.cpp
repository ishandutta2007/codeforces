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
int hol[100009];
int test;
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            int aaa;
            cin>>aaa;
            hol[aaa]=i;
        }
        ll ans=0;
        int maxi=0;
        for(int i=1; i<=m; i++)
        {
            int x;
            cin>>x;
            if(hol[x]>maxi)
            {
                ans+=((ll)(2*(hol[x]-(i-1))-1));
            }
            else
            {
                ans++;
            }
            maxi=max(maxi, hol[x]);
        }
        cout<<ans<<endl;
    }
    return 0;
}