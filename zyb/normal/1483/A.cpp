#include<bits/stdc++.h>
#define N 100005
using namespace std;
#define pb push_back
#define lowbit(x) x&-x
#define inf 10000000000000ll
int n,m,a[N],d[N];
vector<int>b[N];
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d%d",&n,&m);    
        for (int i=1;i<=n;i++) a[i]=0;
        for (int i=1;i<=m;i++) {
            int k;
            scanf("%d",&k);
            b[i].clear();
            d[i]=0;
            for (int j=1;j<=k;j++) {
                int x;
                scanf("%d",&x);
                b[i].pb(x);
            }
            a[b[i][0]]++;
        }
        int gt=0;
        for (int i=1;i<=n;i++) if (a[i]>(m+1)/2) gt=i;
        if (gt) {
            for (int i=1;i<=m;i++) if ((a[gt]>(m+1)/2) && (b[i][0]==gt) && (b[i].size()>1)) a[gt]--,d[i]=1;
        }
        if (a[gt]<=(m+1)/2) {
            puts("YES");
            for (int i=1;i<=m;i++) printf("%d ",b[i][d[i]]);
            puts("");
        }
        else {
            puts("NO");
        }
    }
}