#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
char t[59][59];
int dp[59][59][59][59];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>t[i][j];
        }
    }
    for(int x1=n-1; x1>=0; x1--)
    {
        for(int x2=x1; x2<n; x2++)
        {
            for(int y1=n-1; y1>=0; y1--)
            {
                for(int y2=y1; y2<n; y2++)
                {
                    if(x1==x2 && y1==y2)
                    {
                        dp[x1][y1][x2][y2]=(t[x1][y1]=='#')?1:0;
                        continue;
                    }
                    dp[x1][y1][x2][y2]=max(x2-x1+1, y2-y1+1);
                    for(int i=x1+1; i<=x2; i++)
                    {
                        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2], dp[x1][y1][i-1][y2]+dp[i][y1][x2][y2]);
                    }
                    for(int j=y1+1; j<=y2; j++)
                    {
                        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2], dp[x1][y1][x2][j-1]+dp[x1][j][x2][y2]);
                    }
                }
            }
        }
    }
    cout<<dp[0][0][n-1][n-1]<<endl;
    return 0;
}