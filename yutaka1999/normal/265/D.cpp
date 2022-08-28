#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 100000000

using namespace std;

bool gcd(int x,int y)
{
    for(int i=min(x,y);i>=2;i--)
    {
        if(x%i==0&&y%i==0) return false;
    }
    return true;
}

int in[100005];
int pos[100005];
int dp[100005];

int near(int x)
{
    if(x==1) return 1;
    int ret=dp[pos[x]];
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ret=max(ret,dp[pos[i]]);
            ret=max(ret,dp[pos[x/i]]);
        }
    }
    return ret+1;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1) dp[i]=1;
        else dp[i]=near(in[i]);
        
        for(int j=1;j*j<=in[i];j++)
        {
            if(in[i]%j==0)
            {
                pos[j]=i;
                pos[in[i]/j]=i;
            }
        }
    }
    int ret=0;
    for(int i=0;i<n;i++) ret=max(ret,dp[i]);
    printf("%d\n",ret);
    return 0;
}