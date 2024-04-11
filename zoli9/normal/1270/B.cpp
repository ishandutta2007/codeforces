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
int test;
int n;
ll a[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n;
        int ans=-1;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            if(i>1 && abs(a[i]-a[i-1])>1)
            {
                ans=i;
            }
        }
        if(ans==-1) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<ans-1<<" "<<ans<<endl;
        }
    }
    return 0;
}