#include<bits/stdc++.h>
#define N 10005
using namespace std;
#define P 998244353
int n,a[N],b[N],k,f[N];
int main() {
    int test;
    scanf("%d",&test);
    int tot=0;
    while (test--) {
        ++tot;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=k;i++) {
            scanf("%d%d",&a[i],&b[i]);
            if (a[i]>b[i]) swap(a[i],b[i]);
            f[a[i]]=f[b[i]]=tot;
        }
        int j=1;
        int s=n-k;
        for (int i=1;i<=2*s;i++) {
            for (;f[j]==tot;j++);
            if (i<=s) a[i+k]=j; 
            else b[i-s+k]=j;
            f[j]=tot;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (a[i]<a[j] && a[j]<b[i] && b[i]<b[j]) ans++;
        printf("%d\n",ans);
    }
}