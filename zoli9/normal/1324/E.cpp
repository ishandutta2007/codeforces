#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int dp[2009][2009];
int t[2009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, h, l, r;
    cin>>n>>h>>l>>r;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int i=n; i>=1; i--)
    {
        for(int x=0; x<h; x++)
        {
            if(l<=(x+t[i])%h && (x+t[i])%h<=r)
            {
                dp[i][x]=1+dp[i+1][(x+t[i])%h];
            }
            else
            {
                dp[i][x]=dp[i+1][(x+t[i])%h];
            }
            int other_score=dp[i+1][(x+t[i]-1)%h];
            if(l<=(x+t[i]-1)%h && (x+t[i]-1)%h<=r) other_score++;
            dp[i][x]=max(dp[i][x], other_score);
        }
    }
    cout<<dp[1][0]<<endl;

    return 0;
}