#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;

int n,m;
int Log2[maxn]={-1};

int f[maxn]={1,2,4};

int main()  {
    for (int i=1;i<maxn;++i) Log2[i]=Log2[i>>1]+1;
    for (int i=3;i<maxn;++i)
        f[i]=f[i-1]*2+1+(~i&1);
    scanf("%d",&n);
    if (n<=2)
        puts("1");
    else    {
        int ans=0;
        for (int i=2;f[i]<=n;++i) 
            if (n==f[i]||n==f[i]+1)
                ans=1;
        printf("%d\n",ans);
    }
    return 0;
}