#include<bits/stdc++.h>
#define maxn 200050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,a[maxn];
int m,b[maxn];

map<int,int> last;

LL dp[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    last[0]=0;
    for (int i=1;i<=n;++i)
        scanf("%d",a+i),last[a[i]]=i;
    for (int i=1;i<=m;++i)  {
        scanf("%d",b+i);
        if (!last.count(b[i]))
            return puts("0"),0;
    }

    for (int i=last[b[1]];i;--i)
        if (a[i]<b[1])
            return puts("0"),0;
    for (int i=last[b[m]];i<=n;++i)
        if (a[i]<b[m])
            return puts("0"),0;

    dp[1]=1;
    for (int i=2,j;i<=m;++i)  {
        int l=last[b[i-1]],r=last[b[i]];
        if (l>r)
            return puts("0"),0;

        for (j=r;j>l;--j)
            if (a[j]<b[i])
                break;
        bool flag=1;
        for (int k=l;k<r;++k)
            if (a[j]<b[i-1])
                flag=0;

        if (!flag)
            return puts("0");
        dp[i]=dp[i-1]*(r-j)%modu;

        // cout<<i<<":"<<dp[i]<<endl;
    }
    printf("%lld\n",dp[m]);
    return 0;
}