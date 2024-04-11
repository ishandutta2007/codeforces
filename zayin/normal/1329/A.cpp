#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

int n,m;
LL l[maxn],p[maxn];

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
        scanf("%lld",l+i);
    
    LL L=0;
    for (int i=1;i<=m;++i)  {
        L+=l[i];
        if (n-l[i]<i-1)
            return puts("-1"),0;
    }

    if (L<n)
        return puts("-1"),0;

    LL len=0;
    for (int i=m;i;--i) {
        if (len+l[i]>=n-i+1)   {
            len=1e9;
            p[i]=i;
        }  else    {
            len+=l[i];
            p[i]=n-len+1;
        }
    }

    for (int i=1;i<=m;++i)
        printf("%d ",p[i]);

    return 0;
}