#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
LL a[maxn],A;

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=A=0;i<n;++i)
            scanf("%lld",a+i),A+=a[i];
        sort(a,a+n);
        if (!A)
            puts("NO");
        else    {
            puts("YES");
            if (A>0)
                reverse(a,a+n);
            for (int i=0;i<n;++i)
                printf("%lld ",a[i]);
            puts("");
        }
    }
    return 0;
}