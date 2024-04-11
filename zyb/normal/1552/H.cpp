#include<bits/stdc++.h>
#define N 205
using namespace std;
#define P 998244353
int n,lastv,sv;
struct pa {
    int x,y;
}A[N*N];
inline int ask(int x,int y) {
    int tot=0;
    for (int i=1;i<=200;i++)
    for (int j=1;j<=200;j++)
    if (i%x==0 && j%y==0) A[++tot]=pa{i,j};
    if (!tot) return 0;
    printf("? %d\n",tot);
    for (int i=1;i<=tot;i++) printf("%d %d ",A[i].x,A[i].y); 
    puts("");
    fflush(stdout);
    scanf("%d",&x);
    return x;
}
inline bool check(int x) {
    lastv=ask(1<<x,1<<x);
    
    long long s=lastv<<(x<<1);
    return (s==sv);
}
inline int print(int s,int l) {
    return (s<<(l+1))-4;
}
int main() {
    sv=ask(1,1);
    if (sv==128*128) {
        puts("! 508");
        fflush(stdout);
        return 0;
    }
    int s=0,x=sv;
    int vr=-1;
    for (;!(x&1);x>>=1) s++;
    int l=0,r=(s>>1)+1;
    while (l+1<r) {
        int mid=(l+r+1)>>1;
        if (check(mid)) l=mid;
        else r=mid,vr=lastv;
    }
    
    if ((l<<1)==s) {
        int m=(sv>>(l<<1));
        s=ask(1<<l,1<<(l+1));
        x=abs(s-(m-s));
        int y=m/x;
        printf("! %d\n", print(x+y,l));
        fflush(stdout);
        return 0;
    }
    int m=(sv>>(l<<1));
    if (vr==-1) check(r),vr=lastv;
    x=abs(vr-((m>>1)-vr))<<1;
    int y=m/x;
    printf("! %d\n",print(x+y,l));
    fflush(stdout);
}