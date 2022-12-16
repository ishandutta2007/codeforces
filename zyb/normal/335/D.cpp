#include<stdio.h>
#define N 3005
#define M 100005
using namespace std;
int i,j,k,s,n,m,R[N][N],L[N][N],U[N][N],D[N][N],F[N][N];
int T[N][N],S,Q[M],f[N][N],uu[N][N],dd[N][N],ll[N][N],rr[N][N],l[M],r[M],d[M],u[M];
inline int check(int x,int y,int xx,int yy) {
    if (f[xx][yy]-f[x-1][yy]-f[xx][y-1]+f[x-1][y-1]!=(xx-x+1)*(yy-y+1)) return 2;
    if (uu[x][yy]-uu[x][y-1]!=yy-y+1) return 2;
    if (dd[xx][yy]-dd[xx][y-1]!=yy-y+1) return 1;
    if (ll[xx][y]-ll[x-1][y]!=xx-x+1) return 2;
    if (rr[xx][yy]-rr[x-1][yy]!=xx-x+1) return 1;
    return 3;
}
inline void print(int x,int y,int xx,int yy) {
    printf("YES ");
    for (int i=1;i<=n;i++) {
        if (u[i]>=x&&u[i]<=xx)
        if (d[i]>=x&&d[i]<=xx)
        if (l[i]>=y&&l[i]<=yy)
        if (r[i]>=y&&r[i]<=yy)
        Q[++S]=i;
    }
    printf("%d\n",S);
    for (int i=1;i<=S;i++) printf("%d ",Q[i]);
    puts("");
}
inline int in() {
    char c=getchar();
    int s=0;
    while (c<'0') c=getchar();
    while (c>='0') s=s*10+c-48,c=getchar();
    return s;
}
int main() {
    scanf("%d",&n);
    int ma=0,MA=0;
    for (i=1;i<=n;i++) {
        u[i]=in(),l[i]=in(),d[i]=in(),r[i]=in();
        if (d[i]>ma) ma=d[i];
        if (r[i]>MA) MA=r[i];
        l[i]++; u[i]++;
        T[u[i]][l[i]]++; T[d[i]+1][l[i]]--;
        T[u[i]][r[i]+1]--; T[d[i]+1][r[i]+1]++;
        U[u[i]][l[i]]++,U[u[i]][r[i]+1]--;
        D[d[i]][l[i]]++,D[d[i]][r[i]+1]--;
        L[u[i]][l[i]]++;L[d[i]+1][l[i]]--;
        R[u[i]][r[i]]++;R[d[i]+1][r[i]]--;
    }
    for (i=1;i<=3000;i++) for (j=1;j<=3000;j++) T[i][j]+=T[i-1][j];
    for (i=1;i<=3000;i++) for (j=1;j<=3000;j++) F[i][j]=F[i][j-1]+T[i][j];
    int s=0,ss;
    for (i=1;i<=3000;i++) for (j=1;j<=3000;j++) {
        s=F[i][j];
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(s>0);
    }
    for (i=1;i<=3000;i++) {
        s=ss=0;
        for (j=1;j<=3000;j++) {
            s+=U[i][j];
            ss+=D[i][j];
            uu[i][j]=uu[i][j-1]+(s>0);
            dd[i][j]=dd[i][j-1]+(ss>0);
        }
    }
    for (j=1;j<=3000;j++) {
        s=ss=0;
        for (i=1;i<=3000;i++) {
            s+=L[i][j];
            ss+=R[i][j];
            ll[i][j]=ll[i-1][j]+(s>0);
            rr[i][j]=rr[i-1][j]+(ss>0);
        }
    }
    for (i=1;i<=n;i++) {
        int gt;
        if (r[i]-l[i]+1>d[i]-u[i]+1) gt=r[i]-l[i]+1;
        else gt=d[i]-u[i]+1;
        for (j=gt-1;j<=3000;j++) {
            if (j+l[i]>MA||j+u[i]>ma) break;
            //if (j+l[i]<r[i]||j+u[i]<d[i]) continue;
            int gtw=check(u[i],l[i],u[i]+j,l[i]+j);
            if (gtw==3) {
                print(u[i],l[i],u[i]+j,l[i]+j);
                return 0;
            }
            else if (gtw==2) break;
        }
    }
    printf("NO\n");
}