#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    scanf("%d%d",&n,&m);
    if (n==1&&m==1) return puts("0"),0;
    if (n==1) {
        for (int i=1;i<=m;i++) printf("%d ",i+1);
        return puts(""),0;
    }
    if (m==1) {
        for (int i=1;i<=n;i++) printf("%d\n",i+1);
        return 0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=n+1;j<=n+m;j++) printf("%d ",i*j);
        puts("");
    }
}