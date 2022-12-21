#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,a[N][6];
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        for (int j=1;j<=5;j++) scanf("%d",&a[i][j]);
        int s=1;
        for (int i=2;i<=n;i++) {
            int t=0;
            for (int j=1;j<=5;j++) {
                if (a[i][j]<a[s][j]) t++;
            }
            if (t>=3) s=i;
        }
        int f=0;
        for (int i=1;i<=n;i++) {
            if (i==s) continue;
            int t=0;
            for (int j=1;j<=5;j++) {
                if (a[i][j]<a[s][j]) t++;
            }
            if (t>=3) f=1;
        }
        if (f) s=-1;
        printf("%d\n",s);
    }
}