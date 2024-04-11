#include<bits/stdc++.h>
#define maxm 21
#define maxn 1000050
#define modu 1000000007
using namespace std;
typedef long long LL;

int n,Log2[maxn]={-1};
LL dp[2][maxm][2];

int f(int x,int y)  {
    return n/(1<<x)/(y?3:1);
}

void add(LL &x,LL y)    {
    x=(x+y)%modu;
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  Log2[i]=Log2[i>>1]+1;

    int now=0;
    dp[now][Log2[n]][0]=1;
    if ((1<<Log2[n]-1)*3<=n)
        dp[now][Log2[n]-1][1]=1;
    for (int i=1;i<n;++i)  {
        memset(dp[now^1],0,sizeof(dp[now^1]));
        for (int a=0;a<=Log2[n];++a)
            for (int b=0;b<=1;++b)  {
                add(dp[now^1][a][b],dp[now][a][b]*(f(a,b)-i));
                if (a)
                    add(dp[now^1][a-1][b],dp[now][a][b]*(f(a-1,b)-f(a,b)));
                if (b)
                    add(dp[now^1][a][b-1],dp[now][a][b]*(f(a,b-1)-f(a,b)));
            }
        now^=1;
    }
    printf("%lld\n",dp[now][0][0]);
    return 0;
}