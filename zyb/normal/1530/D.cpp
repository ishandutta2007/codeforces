#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,a[N],b[N],v[N];
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++) scanf("%d",&a[i]), v[i]=b[i]=0;
        
        for (int i=1;i<=n;i++) {
            if (!v[a[i]]) {
                b[i]=a[i];
                v[a[i]]=i;
            }
            else b[i]=0;
        }
        int j=1;
        for (int i=1;i<=n;i++) {
            if (!b[i]) {
                while (v[j]) j=j+1;
                b[i]=j;
                v[j]=i;
            }
            
        }
        for (int i=1;i<=n;i++) {
            if (b[i]==i) {
                int x=v[a[i]];
                b[x]=i;
                b[i]=a[i];
                v[i]=x;
                v[a[i]]=i;
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++) if (a[i]==b[i]) ans++;
        printf("%d\n",ans);
        for (int i=1;i<=n;i++) printf("%d ",b[i]);
        puts("");
    }
}