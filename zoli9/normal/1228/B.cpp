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

int t[1009][1009];
int h, w;
ll ans=1;
ll MOD=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>h>>w;
    for(int i=1; i<=h; i++)
    {
        int k;
        cin>>k;
        for(int j=1; j<=k; j++)
        {
            t[i][j]=1;
        }
        t[i][k+1]=2;
    }
    for(int j=1; j<=w; j++)
    {
        int k;
        cin>>k;
        for(int i=1; i<=k; i++)
        {
            if(t[i][j]==2)
            {
                cout<<0<<endl;
                return 0;
            }
            t[i][j]=1;
        }
        if(t[k+1][j]==1)
        {
            cout<<0<<endl;
            return 0;
        }
        t[k+1][j]=2;
    }
    for(int i=1; i<=h; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(t[i][j]==0) ans=(ans*2)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}