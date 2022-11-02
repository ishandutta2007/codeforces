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
int n;
int a[200009];
int dp[200009];
int dp2[200009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    dp2[1]=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(i>1)
        {
            if(a[i]>a[i-1]) dp2[i]=dp2[i-1]+1;
            else dp2[i]=1;
        }
    }
    dp[n]=1;
    int ans=1;
    for(int i=n-1; i>=1; i--)
    {
        if(a[i]<a[i+1]) dp[i]=dp[i+1]+1;
        else dp[i]=1;
        ans=max(ans, dp[i]);
    }
    for(int i=2; i<n; i++)
    {
        if(a[i-1]<a[i+1])
        {
            ans=max(ans, dp2[i-1]+dp[i+1]);
        }
    }
    cout<<ans<<endl;

    return 0;
}