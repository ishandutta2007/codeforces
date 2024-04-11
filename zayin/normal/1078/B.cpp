#include<bits/stdc++.h>
#define maxn 105
#define maxm 10050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m,type;
int a[maxn];

int cnt[maxn];

void init()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]),m+=a[i];
        if (++cnt[a[i]]==1)
            ++type;
    }
}

LL C[maxn][maxn];
LL dp[maxn][maxm]; 

void upd(LL &x,LL y)
{
    if ((x+=y)>=modu)
        x-=modu;
}

int solve()
{
    if (type<=2)
        return n;
    
    for (int i=0;i<=n;++i)
    {
        C[i][0]=1;
        for (int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%modu;
    }

    dp[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        for (int k=i;k;--k)
            for (int j=a[i];j<=m;++j)
                upd(dp[k][j],dp[k-1][j-a[i]]);
                
        // for (int i=1;i<=n;++i)
        //     for (int j=0;j<=m;++j)
        //         if (dp[i][j])
        //             printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        // cout<<"----------"<<endl;
    }
    
    // cout<<"???"<<endl;
    // for (int i=1;i<=n;++i)
    //     for (int j=0;j<=m;++j)
    //         if (dp[i][j])
    //             printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
    int ans=0;
    for (int i=0;i<maxn;++i)
        for (int c=1;c<=cnt[i];++c)
            if (dp[c][c*i]==C[cnt[i]][c])
                ans=max(ans,c);
    return ans;
}

int main()
{
    init();
    printf("%d\n",solve());
    return 0;
}