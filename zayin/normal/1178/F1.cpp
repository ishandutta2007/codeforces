#include<bits/stdc++.h>
#define maxn 505
#define modu 998244353;
using namespace std;
typedef long long LL;

int n,m;
int a[maxn];
int ST[maxn][maxn];

int Min(int i,int j)    {
    return a[i]<a[j]?i:j;
}

void init() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    for (int i=1;i<=n;++i)  {
        ST[i][i]=i;
        for (int j=i+1;j<=n;++j)
            ST[i][j]=Min(ST[i][j-1],j);
    }
}

bool vis[maxn][maxn];
LL dp[maxn][maxn];

LL calc(int l,int r)    {
    if (l>=r)   return 1;
    if (vis[l][r])  return dp[l][r];
    vis[l][r]=1;
    int p=ST[l][r];
    // cout<<"calc:"<<l<<" "<<r<<" "<<p<<endl;
    LL L=calc(l,p-1),R=calc(p+1,r);
    for (int i=l;i<p;++i)
        L=(L+calc(l,i-1)*calc(i,p-1))%modu;
    for (int i=r;i>p;--i)
        // cout<<l<<" "<<r<<" -> "<<p+1<<" "<<i<<" + "<<i+1<<" "<<r<<endl,
        R=(R+calc(p+1,i)*calc(i+1,r))%modu;
    return dp[l][r]=L*R%modu;
}

int main()  {
    init();
    printf("%lld\n",calc(1,n));
    return 0;
}