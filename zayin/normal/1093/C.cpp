#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
LL b[maxn];

LL a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<(n>>1);++i)
        scanf("%lld",b+i);
    LL l=0,r=1LL<<60;
    for (int i=0;i<(n>>1);++i)
    {
        if (b[i]-l<=r)
            a[i]=l,a[n-i-1]=b[i]-l;
        else
            a[n-i-1]=r,a[i]=b[i]-r;
        l=a[i],r=a[n-i-1];
    }
    for (int i=0;i<n;++i)
        printf("%lld ",a[i]);
    return 0;
}