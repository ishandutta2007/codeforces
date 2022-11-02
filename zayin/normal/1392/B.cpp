#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

LL m;
int n,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%lld",&n,&m);

        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        if (m>10)
            m=m%10+10;
        
        while (m--) {
            int mxa=-1e9;
            for (int i=1;i<=n;++i)  
                mxa=max(mxa,a[i]);
            for (int i=1;i<=n;++i)
                a[i]=mxa-a[i];
        }
        for (int i=1;i<=n;++i)
            printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}