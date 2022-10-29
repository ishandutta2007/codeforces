#include <bits/stdc++.h>
using namespace std;

const int N = 56;
const int INF = 0x3f3f3f3f;

int dp[2][N];
int a[N];

int solve(int per,int now)
{
    if (a[now] == 0) return 0;
    else if (dp[per][now] != INF) return dp[per][now];
    return dp[per][now] = max(solve(per,now+1)-a[now],-solve(1-per,now+1)+a[now]);
}

int main ()
{
    memset(dp,INF,sizeof(dp));
    int n;
    scanf("%d",&n);
    int tot=0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        tot += a[i];
    }
    int delta = solve(0,1);
    printf("%d %d\n",(tot-delta)/2,(tot+delta)/2);
}