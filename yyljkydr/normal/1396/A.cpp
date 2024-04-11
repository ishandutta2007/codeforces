#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

typedef long long ll;

int n;

ll a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(n==1)
    {
        for(int i=1;i<=3;i++)
            puts("1 1"),printf("%lld\n",(i&1?-1:1)*a[i]);
    }
    else
    {
        printf("%d %d\n",1,n);
        for(int i=1;i<=n;i++)
        {
            ll A=(a[i]-a[i]%n)/n+(a[i]%n);
            printf("%lld ",-A*n); 
            if(i==n)
                a[n]-=A*n;
        }
        puts("");
        printf("%d %d\n",1,n-1);
        for(int i=1;i<=n-1;i++)
        {
            ll A=-a[i]%n;
            printf("%lld ",-A*(n-1)); 
        }
        puts("");
        printf("%d %d\n",n,n);
        printf("%lld\n",-a[n]);
    }
}