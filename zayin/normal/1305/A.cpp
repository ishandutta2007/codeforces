#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,a[maxn],b[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",a+i);
        for (int i=1;i<=n;++i) scanf("%d",b+i);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        for (int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
        for (int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
    }
    return 0;
}