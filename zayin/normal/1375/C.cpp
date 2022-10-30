#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

int n,a[maxn];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%d",a+i);
        puts(a[1]<a[n]?"YES":"NO");
    }
    return 0;
}