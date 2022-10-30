#include<bits/stdc++.h>
#define maxn 100000
using namespace std;

int n,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        for (int i=1;i<=n;++i)  {
            int x=abs(a[i]);
            if (i&1)
                x=-x;
            printf("%d ",x);
        }
        puts("");
    }
    return 0;
}