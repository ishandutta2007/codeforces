#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

LL n,a[maxn],b[maxn],x[maxn];
int main()  {
    scanf("%lld",&n);
    for (int i=1;i<=n;++i)  {
        x[i]=max(x[i-1],a[i-1]);
        scanf("%lld",b+i);
        a[i]=b[i]+x[i];
        printf("%lld ",a[i]);
    }
    return 0;
}