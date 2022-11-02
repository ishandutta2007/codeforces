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
    cin>>test;
    int n;
    for(int tt=1; tt<=test; tt++)
    {
        bool nagy=false;
        cin>>n;
        ll bob=0;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            bob+=a[i];
        }
        ll alice=-1e17;
        ll sum=0;
        ll mini=0;
        ll mini2=1e17;
        for(int i=1; i<=n; i++)
        {
            sum+=a[i];
            if(sum<mini)
            {
                mini2=mini;
                mini=sum;
            }
            else if(sum<mini2)
            {
                mini2=sum;
            }
            if(i<n)
            {
                if(sum-mini>=bob)
                {
                    nagy=true;
                    break;
                }
            }
            else
            {
                if(sum-mini2>=bob)
                {
                    nagy=true;
                    break;
                }
            }
        }
        if(nagy) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}