#include<bits/stdc++.h>
#define maxn 100050
#define modu 1000000007
using namespace std;
typedef long long LL;

int n,m;
LL f[maxn]={1,1};

int main()  {
    scanf("%d%d",&n,&m);
    for (int i=2;i<maxn;++i)    
        f[i]=(f[i-2]+f[i-1])%modu;
    LL ans=(f[n]*2+f[m]*2-2+modu)%modu;
    printf("%lld\n",ans);
    return 0;
}