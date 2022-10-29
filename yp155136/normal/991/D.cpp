#include <bits/stdc++.h>
using namespace std;

int a[3][106];
int pre[3][106];
int dp[106];

int cal(int x1,int y1,int x2,int y2)
{
    if (x1 <= 0 || y1 <= 0) return 0;
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

int main ()
{
    int n;
    for (int i=0;2>i;i++)
    {
        string s;
        cin >>s;
        n = s.size();
        for (int j=1;n>=j;j++)
        {
            char c=s[j-1];
            if (c == '0') a[i+1][j] = 1;
        }
    }
    for (int i=1;2>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            pre[i][j] = pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1] + a[i][j];
        }
    }
    for (int i=1;n>=i;i++)
    {
        dp[i] = dp[i-1];
        if (cal(1,i-1,2,i) >= 3) dp[i] = max(dp[i],dp[i-2]+1);
        if (cal(1,i-2,2,i) == 6) dp[i] = max(dp[i],dp[i-3]+2);
    }
    cout << dp[n] <<endl;
}