#include<stdio.h>
#define P 1000000007
#define N 500000
#define NN 500005
#include<algorithm>
#define inf 1000000000000000000
using namespace std;
struct node {
    long long x,v;
}f[NN*2];
long long i,j,k,l,s,n,m,r,ans,x,y,ma[NN*2],Ma[NN*2],mx,my,mix,miy,X,Y,q;
inline long long workx(long long o) {
    long long gt=min(ma[n-o+1+N],ma[-o+N]);
    if (gt!=inf) return gt;
    if (X==0) return inf; 
    if (X>0) {
        long long p=n-mx+1;
        long long dis=p-o;
        dis=(dis-1)/X+1;
        o=o+X*dis;
        gt=dis*q;
        return gt+ma[n-o+1+N];
    }
    else {
        long long p=-mix;
        long long dis=o-p;
        dis=(dis-1)/(-X)+1;
        o=o+X*dis;
        gt=dis*q;
        return gt+ma[-o+N];
    }
}
inline long long worky(long long o) {
    long long gt=min(Ma[m-o+1+N],Ma[-o+N]);
    if (gt!=inf) return gt;
    if (Y==0) return inf; 
    if (Y>0) {
        long long p=m-my+1;
        long long dis=p-o;
        dis=(dis-1)/Y+1;
        o=o+Y*dis;
        gt=dis*q;
        return gt+Ma[m-o+1+N];
    }
    else {
        long long p=-miy;
        long long dis=o-p;
        dis=(dis-1)/(-Y)+1;
        o=o+Y*dis;
        gt=dis*q;
        return gt+Ma[-o+N];
    }
}
inline bool cmp(const node &x,const node &y) {
    return x.v<y.v;
}
int main() {
    scanf("%I64d%I64d%I64d",&q,&m,&n);
    for (i=-N;i<=N;i++) ma[i+N]=Ma[i+N]=inf;
    for (i=1;i<=q;i++) {
        char c=getchar();
        while (c!='L'&&c!='R'&&c!='U'&&c!='D') c=getchar();
        if (c=='L') x--;
        else if (c=='R') x++;
        else if (c=='U') y--;
        else y++;
        Ma[y+N]=min(Ma[y+N],i);
        ma[x+N]=min(ma[x+N],i);
        mx=max(mx,x);
        my=max(my,y);
        mix=min(mix,x);
        miy=min(miy,y);
    }
    X=x,Y=y;
    long long s=0,S=0;
    for (i=1;i<=n;i++) 
     f[++r].x=1,f[r].v=workx(i);
    for (i=1;i<=m;i++) 
     f[++r].x=2,f[r].v=worky(i);
    sort(f+1,f+1+r,cmp);
    for (i=1;i<=r;i++) if (f[i].v==inf) {
        if (f[i].x==1) s++;
        else S++;
    }
    if (s&&S) return printf("-1"),0;
//  if (f[r].v==inf) return printf("-1"),0;
    for (i=1;i<=r;i++) {
        if (f[i].x==1) (ans+=m*f[i].v)%=P,n--;
        else (ans+=n*f[i].v)%=P,m--;
    }
    printf("%I64d\n",ans);
 }