#include<bits/stdc++.h>
#define maxn 13
#define maxm 2050
#define maxs 4150
using namespace std;

int n,m,S;

int pos[maxm],val[maxm];
int a[maxn][maxm];

int sum[maxs],low[maxs],er[maxs];

int b[maxn];
int dp[2][maxs],st[maxs];

int main()  {
    for (int s=1;s<maxs;++s)
        for (int i=0;i<maxn;++i)
            if (s>>i&1) {
                low[s]=i,er[s]=1<<i;
                break;
            }

    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m),S=1<<n;
        for (int j=0;j<m;++j)   val[j]=0,pos[j]=j;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)   {
                scanf("%d",a[i]+j);
                val[j]=max(val[j],a[i][j]);
            }
        sort(pos,pos+m,[&](const int& i,const int& j)   {
            return val[i]>val[j];
        });
        int now=0;
        for (int s=0;s<S;++s)   dp[now][s]=0;
        for (int k=0;k<m&&k<n;++k)   {
            now^=1;
            for (int s=0;s<S;++s)   dp[now][s]=dp[now^1][s];
            for (int s=0;s<S;++s)   st[s]=0;
            for (int f=0;f<n;++f)   {
                for (int i=0;i<n;++i)   b[i]=a[(f+i)%n][pos[k]];
                sum[0]=0;
                for (int s=1;s<S;++s)   {
                    sum[s]=sum[s^er[s]]+b[low[s]];
                    st[s]=max(st[s],sum[s]);
                }
            }
            for (int s=1;s<S;++s)
                for (int t=s;t;t=(t-1)&s)
                    dp[now][s]=max(dp[now][s],dp[now^1][s^t]+st[t]);
            // cout<<k<<":"<<pos[k]<<endl;
            // for (int s=0;s<S;++s)   cout<<st[s]<<" "; cout<<endl;
            // for (int s=0;s<S;++s)   cout<<dp[now][s]<<" "; cout<<endl;
        }
        printf("%d\n",dp[now][S-1]);
    }
    return 0;
}