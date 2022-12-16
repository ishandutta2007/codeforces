#include<stdio.h>
#include<cstring>
using namespace std;
long long f[65536],P;
int a[17][17],b[17],ans[17],v[17],x,y,n,m,i,j,k,l;
inline bool check(int o) {
    for (int i=1;i<o;i++) if ((a[o][i]&&ans[o]<ans[i])||(a[i][o]&&ans[o]>ans[i])) return false;
    return true;
}
inline long long dp(int o) {
    if (!check(o)) return 0;
    memset(f,0,sizeof(f));
    f[(1<<(o))-1]=1;
    int gt=(1<<(n))-1;
    for (int i=1;i<=n;i++) {
        if (v[i]) continue;
        for (int j=gt;j>=0;j--) if (f[j]) {
            
            for (int k=o+1;k<=n;k++) {
                if ((j&(1<<(k-1)))||((b[k]&j)!=b[k])) continue;
                int bb=0;
                for (int l=1;l<=o;l++) if ((a[k][l]&&i<ans[l])||(a[l][k]&&i>ans[l])) {
                    bb=1; break;
                }
                if (bb) continue;
                f[j|(1<<(k-1))]+=f[j];
            }
            f[j]=0;
        }
        
    }
    return f[gt];
}
int main() {
    scanf("%d%I64d%d",&n,&P,&m);
    P-=2000;
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        if (!a[y][x])
        a[y][x]=1,b[y]+=1<<(x-1);
    }
    if (dp(0)<P) return puts("The times have changed"),0;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++) {
        if (v[j]) continue;
        ans[i]=j,v[j]=1;
        //S+=(1<<(j-1));
        long long gt=dp(i);
        if (gt>=P) break;
        else P-=gt,v[j]=0;//,S-=(1<<(j-1));
    }
    for (int i=1;i<=n;i++) printf("%d ",ans[i]);
}