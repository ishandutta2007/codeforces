#include<stdio.h>
using namespace std;
struct node {
    double f;
}f[205][205][505];
int i,j,k,l,s,m,n,b[100005],s1;
double a[10005],s2;
int main() {
    scanf("%d%d%d",&n,&l,&k);
    for (i=1;i<=n;i++) scanf("%d",&j),a[i]=j/100.0;
    for (i=1;i<=n;i++) scanf("%d",&b[i]);
    f[0][0][k+200].f=1;
    for (i=1;i<=n;i++)
    for (int j=0;j<i;j++)
    for (int k=0;k<=400;k++) {
        f[i][j][k].f+=f[i-1][j][k].f*(1-a[i]);
        
            if (b[i]>0) {
                int gt=k+b[i];
                if (gt>400) gt=400;
                f[i][j+1][gt].f+=(f[i-1][j][k].f*a[i]);
                
            }
            else {
                int gt=k-1;
                if (gt<0) continue;
                f[i][j+1][gt].f+=(f[i-1][j][k].f*a[i]);
            }
        
    }
    for (j=l;j<=n;j++)
    for (k=0;k<=200;k++) {
        s2+=f[n][j][k+200].f;
    }
    printf("%lf",s2);
}