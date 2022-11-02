#include<bits/stdc++.h>
#define maxn 2050
using namespace std;
typedef long long LL;

char str[maxn][maxn];

int n,m,q;
int N,M;
LL a[maxn][maxn],s[maxn][maxn];

LL L[maxn],U[maxn];

void init() {
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=n;++i)
        scanf("%s",str[i]+1);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            a[i][j]=str[i][j]-'0';
    for (int i=1;i<=n;++i)
        for (int j=m+1;j<=2*m;++j)
            a[i][j]=a[i][j-m]^1;
    for (int i=n+1;i<=2*n;++i)
        for (int j=1;j<=m;++j)
            a[i][j]=a[i-n][j]^1;
    for (int i=n+1;i<=2*n;++i)
        for (int j=m+1;j<=2*m;++j)
            a[i][j]=a[i-n][j-m];
    
    N=n<<1,M=m<<1;
    for (int i=1;i<=N;++i)
        for (int j=1;j<=M;++j)
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
    for (int i=1;i<=N;++i)  {
        U[i]=U[i-1];
        for (int j=1;j<=M;++j)
            U[i]+=a[i][j];
    }

    for (int j=1;j<=M;++j)  {
        L[j]=L[j-1];
        for (int i=1;i<=N;++i)
            L[j]+=a[i][j];
    }
}

LL find(LL p)   {
    --p;
    int ans=0;
    for (int i=0;i<=30;++i)
        if (p>>i&1)
            ans^=1;
    return ans;
}

LL calc(LL x,LL y)  {
    LL _n=x/N,_m=y/M;
    LL ans=_n*_m*s[N][M];
    // cout<<_n<<" "<<_m<<" "<<s[N][M]<<endl;
    if (x%N)    {
        // cout<<"sol1"<<endl;
        int I=find(_n+1);
        if (!I)
            ans+=U[x%N]*_m;
        else
            ans+=(x%N*M-U[x%N])*_m;
    }
    // cout<<"ans1:"<<ans<<endl;
    if (y%M)    {
        // cout<<"sol2"<<endl;
        int I=find(_m+1);
        if (!I)
            ans+=L[y%M]*_n;
        else
            ans+=(y%M*N-L[y%M])*_n;
    }
    // cout<<"ans2:"<<ans<<endl;
    if (x%N&&y%M)   {
        int I=find(_n+1)^find(_m+1);
        // cout<<find(_n+1)<<" "<<find(_m+1)<<endl;
        // cout<<"sol3"<<":"<<I<<" "<<x%N<<" "<<y%M<<" "<<s[x%N][y%M]<<endl;
        if (!I)
            ans+=s[x%N][y%M];
        else
            ans+=(x%N)*(y%M)-s[x%N][y%M];
    }
    // cout<<"r_ans:"<<ans<<endl;
    // cout<<endl;
    return ans;
}

void solve()    {
    while (q--) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%lld\n",calc(x2,y2)+calc(x1-1,y1-1)-calc(x2,y1-1)-calc(x1-1,y2));
    }
}

int main()  {
    init();
    solve();
    return 0;
}