#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,a[55][55];
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d%d",&n,&m);
        for (int i=0;i<=n+5;i++)
        for (int j=0;j<=m+5;j++) a[i][j]=0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            if (i>1&&i<n&&j>1&&j<m) continue;
            int f=0;
            for (int x=-1;x<=1;x++)
            for (int y=-1;y<=1;y++) if (a[i+x][j+y]) f=1;
            if (!f) a[i][j]=1;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) printf("%d",a[i][j]);
            puts("");
        }
        puts("");
    }
}