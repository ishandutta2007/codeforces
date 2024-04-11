#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n,m;
int a[maxn],b[maxn];

void init() {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)  {
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;++i)  {
        scanf("%d",b+i);
        if (b[i]==1)
            m=i;
    }
}

int f[maxn];

bool spc()  {
    for (int i=1;i<=n;++i)  f[i]=0;
    for (int i=1;i<=n;++i)  f[a[i]]=1;
    for (int i=m;i<=n;++i)
        if (b[i]!=i-m+1)
            return 0;
    if (m==1)   return 1;
    int p=n-m+2;
    for (int i=1;i<=n;++i)  {
        if (!f[p])  return 0;
        ++p;
        if (p>n)    break;
        ++f[b[i]];
    }
    return 1;
}

bool judge(int x)   {
    for (int i=1;i<=n;++i)  f[i]=0;
    for (int i=1;i<=n;++i)
        if (a[i])
            f[a[i]]=1;
    for (int i=1;i<=x;++i)
        if (b[i])
            f[b[i]]=1;
    int p=1;
    for (int i=x+1;i<=n;++i)    {
        if (!f[p])  return 0;
        ++p;
        if (p>n)    break;
        if (b[i])
            f[b[i]]=1;
    }
    return 1;
}

void solve()    {
    int l=0,r=n;
    while (l<r) {
        int mid=(l+r)>>1;
        if (judge(mid))
            r=mid;
        else
            l=mid+1;
    }
    printf("%d\n",l+n);
}

int main()  {
    init();
    if (!spc())
        solve();
    else
        printf("%d\n",m-1);
    return 0;
}