#include<stdio.h>
#define N 1005
using namespace std;
int i,j,k,l,s,n,m,a[N][N],v[N];
inline void work(int o) {
    for (i=1;i<=o;i++) for (j=1;j<=o/2;j++) a[i][(j+i-1)%o+1]=1;
    for (i=1;i<=o;i++) {
        for (j=1;j<=o;j++) printf("%d ",a[i][j]);
        puts("");
    }
}
inline void work1(int o) {
    if (o==4) {
        printf("-1\n");
        return ;
    }
    o=n-1;
    for (i=1;i<=o;i++) for (j=1;j<=o/2;j++) a[i][(j+i-1)%o+1]=1;
    int j=1;
    while (j<=o)
    a[n][j]=1,v[j]=1,j+=o/2+1;
    for (i=1;i<=o;i++) if (!v[i]) a[i][n]=1;
    for (i=1;i<=n;i++) {
        for (j=1;j<=n;j++) printf("%d ",a[i][j]);
        puts("");
    }
}
int main() {
    scanf("%d",&n);
    if (n&1) work(n);
    else work1(n);
}