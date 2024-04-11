#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#define SIZE 105
#define MX 25
#define BT 1<<21
#define INF 1000000000

using namespace std;

int val[SIZE];
char str[5];
int in[MX],tm[MX];
int dp[MX][BT];
int n,m;

void init()
{
    for(int i=0;i<MX;i++)
    {
        for(int j=0;j<BT;j++)
        {
            dp[i][j]=-INF;
        }
    }
}
int memo(int pos,int S)
{
    if(dp[pos][S]!=-INF) return dp[pos][S];
    for(int i=0;i<m;i++)
    {
        if(!(S>>i&1))
        {
            if(in[pos]==0)
            {
                if(pos+1==m) dp[pos][S]=max(dp[pos][S],val[i]);
                else
                {
                    if(tm[pos]==tm[pos+1]) dp[pos][S]=max(dp[pos][S],val[i]+memo(pos+1,S|1<<i));
                    else dp[pos][S]=max(dp[pos][S],-memo(pos+1,S|1<<i)+val[i]);
                }
            }
            else
            {
                if(pos+1==m) dp[pos][S]=max(dp[pos][S],0);
                else
                {
                    if(tm[pos]==tm[pos+1]) dp[pos][S]=max(dp[pos][S],memo(pos+1,S|1<<i));
                    else dp[pos][S]=max(dp[pos][S],-memo(pos+1,S|1<<i));
                }
            }
        }
    }
    return dp[pos][S];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&val[i]);
    sort(val,val+n,greater <int>());
    scanf("%d",&m);
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        scanf("%s %d",&str,&tm[i]);
        tm[i]--;
        if(str[0]=='p') in[i]=0;
        else in[i]=1;
    }
    init();
    int ret=memo(0,0);
    if(tm[0]==1) ret*=-1;
    printf("%d\n",ret);
    return 0;
}