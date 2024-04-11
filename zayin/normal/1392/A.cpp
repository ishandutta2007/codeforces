#include<bits/stdc++.h>
#define maxn 200050
using namespace std;

int n,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        bool flag=1;
        for (int i=2;i<=n;++i)
            flag&=a[i]==a[1];
        printf("%d\n",flag?n:1);
    }
    return 0;
}