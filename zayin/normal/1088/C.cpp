#include<bits/stdc++.h>
#define maxn 2050
using namespace std;
typedef long long LL;

int n;
LL a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%lld",&a[i]);
    
    printf("%d\n",n+1);
    LL sum=0;
    for (int i=n-1;~i;--i)
    {
        a[i]+=sum;
        printf("1 %d %d\n",i+1,(i-a[i])%n+n);
        sum+=(i-a[i])%n+n;
    }
    printf("2 %d %d\n",n,n);
    return 0;
}