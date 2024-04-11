#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
string s, z;
int n, m;
int dp[5009][5009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s>>z;
    int ans=0;
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(s[i]==z[j])
            {
                dp[i][j]=2+dp[i+1][j+1];
            }
            else
            {
                dp[i][j]=max(0, max(dp[i+1][j]-1, dp[i][j+1]-1));
            }
            ans=max(ans, dp[i][j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}