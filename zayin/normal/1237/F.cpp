#include<bits/stdc++.h>
#define maxn 4050
#define modu 998244353
using namespace std;
typedef long long LL;

int h,w;

struct node {
    int x,y;
} P[maxn][2];
int n;

int visl[maxn],visr[maxn];

LL f[maxn][maxn][2];
LL dpl[maxn][maxn],dpr[maxn][maxn];//2 1

LL F[maxn]={1},I[maxn]={1,1};

void add(LL &a,LL b)    {
    a=(a+b)%modu;
}

LL C(int n,int m)   {
    return n>=m?F[n]*I[m]%modu*I[n-m]%modu:0;
}

void solve(int n,LL dp[maxn][maxn],int vis[maxn])    {
    memset(f,0,sizeof(f));
    // for (int i=0;i<=n;++i)
    //     for (int j=0;j<=n;++j)
    //         f[i][j]=0;
    f[0][0][0]=1;
    // for (int i=1;i<=n;++i) cout<<vis[i]<<" "; cout<<endl;
    for (int i=1;i<=n;++i)  {
        for (int j=0;j<=i;++j)  {
            // if (!f[i-1][j]) continue;
            f[i][j][0]=(f[i-1][j][0]+f[i-1][j][1])%modu;
            if (i>1&&!vis[i]&&!vis[i-1])
                // cout<<"add:"<<i<<" "<<j+1<<" "<<f[i-1][j]<<endl,
                add(f[i][j+1][1],f[i-1][j][0]);
        }
        // for (int j=0;j<=i;++j)
        //     if (f[i][j])
        //         cout<<"f:"<<i<<" "<<j<<" "<<f[i][j]<<endl;
    }
    int cnt=0;
    for (int i=1;i<=n;++i) cnt+=vis[i];
    for (int i=0;i<=n;++i)
        for (int j=0;j+cnt+2*i<=n;++j)
            add(dp[i][j],(f[n][i][0]+f[n][i][1])*C(n-cnt-2*i,j));
    // for (int i=0;i<=n;++i)
    //     for (int j=0;j<=n;++j)
    //         if (dp[i][j])
    //             cout<<"dp:"<<i<<" "<<j<<" "<<dp[i][j]<<endl;
}

int main()  {
    for (int i=1;i<maxn;++i) F[i]=F[i-1]*i%modu;
    for (int i=2;i<maxn;++i) I[i]=modu-modu/i*I[modu%i]%modu;
    for (int i=2;i<maxn;++i) I[i]=I[i]*I[i-1]%modu;

    scanf("%d%d%d",&h,&w,&n);
    for (int i=1;i<=n;++i)
        for (int j=0;j<=1;++j)  {
            scanf("%d%d",&P[i][j].x,&P[i][j].y);
            visl[P[i][j].x]=1;
            visr[P[i][j].y]=1;
        }
    
    solve(h,dpl,visl);
    solve(w,dpr,visr);

    LL ans=0;
    for (int i=0;i<=h;++i)
        for (int j=0;j<=w;++j)  
            add(ans,dpl[j][i]*dpr[i][j]%modu*F[i]%modu*F[j]%modu);
    printf("%lld\n",ans);
    return 0;
}