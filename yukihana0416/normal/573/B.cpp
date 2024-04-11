#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID int mid=(l+r)>>1
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))

const int maxn=(int) 1e5+20;

int a[maxn];
int dp[maxn][2];
int n;

int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) a[i]=read();
        dp[0][0]=0;
        dp[0][1]=0;
        dp[n+1][0]=0;
        dp[n+1][1]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=min(a[i],dp[i-1][0]+1);
        }
        for(int i=n;i>=1;i--)
        {
            dp[i][1]=min(a[i],dp[i+1][1]+1);
        }
        int ans=0;
//        for(int i=1;i<=n;i++) cout <<dp[i][0] <<" ";cout <<endl;
//        for(int i=1;i<=n;i++) cout <<dp[i][1] <<" ";cout <<endl;

        for(int i=1;i<=n;i++)
        {
            ans=max(ans,min(dp[i][0],dp[i][1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}