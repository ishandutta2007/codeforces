#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, k;
char t[2009][2009];
int minrow[2009];
int maxrow[2009];
int mincol[2009];
int maxcol[2009];
int ans;
int dp[2009][2009];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>t[i][j];
            if(t[i][j]=='B')
            {
                maxrow[i]=j;
                maxcol[j]=i;
                if(minrow[i]==0) minrow[i]=j;
                if(mincol[j]==0) mincol[j]=i;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(minrow[i]==0)
        {
            ans++;
            continue;
        }
        if(minrow[i]+k<=maxrow[i]) continue;
        int kezdx=max(1, i-k+1);
        int kezdy=max(1, maxrow[i]-k+1);
        int vegx=min(n-k+1, i);
        int vegy=min(n-k+1, minrow[i]);
        dp[kezdx][kezdy]++;
        dp[kezdx][vegy+1]--;
        dp[vegx+1][kezdy]--;
        dp[vegx+1][vegy+1]++;
    }
    for(int i=1; i<=n; i++)
    {
        if(mincol[i]==0)
        {
            ans++;
            continue;
        }
        if(mincol[i]+k<=maxcol[i]) continue;
        int kezdx=max(1, maxcol[i]-k+1);
        int kezdy=max(1, i-k+1);
        int vegx=min(n-k+1, mincol[i]);
        int vegy=min(n-k+1, i);
        dp[kezdx][kezdy]++;
        dp[kezdx][vegy+1]--;
        dp[vegx+1][kezdy]--;
        dp[vegx+1][vegy+1]++;
    }
    int aa=0;
    for(int i=1; i<=n-k+1; i++)
    {
        for(int j=1; j<=n-k+1; j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
            dp[i][j]-=dp[i-1][j-1];
            aa=max(aa, dp[i][j]);
        }
    }
    cout<<aa+ans<<endl;

    return 0;
}