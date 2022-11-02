#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n,a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d",a+i);
    for (int s=0;s<(1<<n);++s)
    {
        int t=0;
        for (int i=0;i<n;++i)
            if (s>>i&1)
                t+=a[i];
            else    
                t-=a[i];
        if (t%360==0)
            return puts("YES"),0;
    }
    puts("NO");
    return 0;
}