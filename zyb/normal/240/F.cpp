#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 100005
using namespace std;
struct node {
    int s[27],d;
}f[N*4];
int b[27],x,y,i,j,k,l,s,n,m,d[27];
char c[N];
inline void up(int o) {
    for (int i=1;i<=26;i++) f[o].s[i]=f[o*2].s[i]+f[o*2+1].s[i];
}
inline void build(int o,int l,int r) {
    if (l==r) {
        f[o].s[c[l]-96]=1; return ;
    }
    int mid=(l+r)>>1;
    build(o*2,l,mid),build(o*2+1,mid+1,r);
    up(o);
}
inline void down(int o,int l,int r) {
    if (f[o].d==1) {
        int mid=(l+r)>>1;   
        int gt=mid-l+1;
        for (int i=1;i<=26;i++) if (f[o].s[i]>gt) f[o*2].s[i]=gt,gt=0;
        else f[o*2].s[i]=f[o].s[i],gt-=f[o].s[i];
        for (int i=1;i<=26;i++) f[o*2+1].s[i]=f[o].s[i]-f[o*2].s[i];
        f[o*2].d=f[o*2+1].d=f[o].d;
        f[o].d=0;
    }
    else {
        int mid=(l+r)>>1;   
        int gt=r-mid;
        for (int i=1;i<=26;i++) if (f[o].s[i]>gt) f[o*2+1].s[i]=gt,gt=0;
        else f[o*2+1].s[i]=f[o].s[i],gt-=f[o].s[i];
        for (int i=1;i<=26;i++) f[o*2].s[i]=f[o].s[i]-f[o*2+1].s[i];
        f[o*2].d=f[o*2+1].d=f[o].d;
        f[o].d=0;
    }
}
inline void ask(int o,int l,int r,int ll,int rr) {
    if (l==ll&&r==rr) {
        for (int i=1;i<=26;i++) b[i]+=f[o].s[i];
        return ;
    }
    if (f[o].d) down(o,l,r);
    int mid=(l+r)>>1;
    if (rr<=mid) ask(o*2,l,mid,ll,rr);
    else if (ll>mid) ask(o*2+1,mid+1,r,ll,rr);
    else ask(o*2,l,mid,ll,mid),ask(o*2+1,mid+1,r,mid+1,rr);
    up(o);
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
    if (ll>rr) return ; 
    if (l==ll&&r==rr) {
        for (int i=1;i<=26;i++) f[o].s[i]=b[i];
        f[o].d=p; return ;
    }
    if (f[o].d) down(o,l,r);
    int mid=(l+r)>>1;
    if (rr<=mid) change(o*2,l,mid,ll,rr,p);
    else if (ll>mid) change(o*2+1,mid+1,r,ll,rr,p);
    else {
        if (p==1) { 
            int c[27],D[27],gt=mid-ll+1;
            for (int i=1;i<=26;i++) c[i]=b[i];
            for (int i=1;i<=26;i++) if (c[i]>gt) {
                D[i]=b[i]=gt,gt=0;
            }
            else D[i]=b[i]=c[i],gt-=c[i];
            change(o*2,l,mid,ll,mid,p);
            for (int i=1;i<=26;i++) b[i]=c[i]-D[i];
            change(o*2+1,mid+1,r,mid+1,rr,p);
        }
        else { 
            int c[27],D[27],gt=rr-mid;
            for (int i=1;i<=26;i++) c[i]=b[i];
            for (int i=1;i<=26;i++) if (c[i]>gt) {
                D[i]=b[i]=gt,gt=0;
            }
            else D[i]=b[i]=c[i],gt-=c[i];
            change(o*2+1,mid+1,r,mid+1,rr,p);
            for (int i=1;i<=26;i++) b[i]=c[i]-D[i];
            change(o*2,l,mid,ll,mid,p);
        }
    }
    up(o);
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",c+1);
    build(1,1,n);
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        memset(b,0,sizeof(b));
        ask(1,1,n,x,y);
        int T=0,gt=0;
        for (int j=1;j<=26;j++) if (b[j]%2) T++,gt=j;
        if (T>1) continue;
        for (int j=1;j<=26;j++) d[j]=(b[j]>>=1);
        if (!gt) {
            change(1,1,n,x,(x+y)>>1,1);
            for (j=1;j<=26;j++) b[j]=d[j]; 
            change(1,1,n,((x+y)>>1)+1,y,2);
        }
        else {
            change(1,1,n,x,((x+y)>>1)-1,1);
            for (j=1;j<=26;j++) b[j]=d[j]; 
            change(1,1,n,((x+y)>>1)+1,y,2);
            memset(b,0,sizeof(b)); b[gt]=1; change(1,1,n,(x+y)>>1,(x+y)>>1,1);
        }
    }
    for (i=1;i<=n;i++) {
        memset(b,0,sizeof(b));
        ask(1,1,n,i,i);
        for (j=1;j<=26;j++) if(b[j]) printf("%c",char(j+96));
    }

}