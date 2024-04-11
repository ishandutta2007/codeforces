#include<cstdio>
#include<cctype>
#include<cmath>
#define R register
#define I inline
using namespace std;
const int S=100003,N=200003;
char buf[1000000],*p1,*p2;
I char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,S,stdin),p1==p2)?EOF:*p1++;}
I int rd(){
    R int f=0; R char c=gc();
    while(c<48||c>57) c=gc();
    while(c>47&&c<58) f=f*10+(c^48),c=gc();
    return f;
}
int h[S],s[N],g[N],p[S],d[S],f[S],o[S],n,c,e;
I int max(int x,int y){return x>y?x:y;}
I void add(int x,int y){s[++c]=h[x],h[x]=c,g[c]=y;}
void dfs(int x,int f){
    for(R int i=h[x],y;i;i=s[i])
        if((y=g[i])^f)
            dfs(y,x);
    p[x]=f,d[++e]=x;
}
I int slv(int k){
    R int i,x,r=0;
    for(i=1;i<=n;++i)
        f[i]=1;
    for(i=1;i<=n;++i){
        x=d[i];
        if(p[x]&&(~f[p[x]])&&(~f[x]))
            if(f[x]+f[p[x]]>=k)
                ++r,f[p[x]]=-1;
            else
                f[p[x]]=max(f[p[x]],f[x]+1);
    }
    return r;
}
int main(){
    R int q,i,j,x,y,t,l,r,m;
    n=rd(),q=sqrt(n*log(n)/log(2));
    for(i=1;i<n;++i)
        x=rd(),y=rd(),add(x,y),add(y,x);
    dfs(1,0),o[1]=n;
    for(i=2;i<=q;++i)
        o[i]=slv(i);
    for(i=q+1;i<=n;i=l+1){
        l=i,r=n,t=slv(i);
        for(;l<r;slv(m)^t?r=m-1:l=m)
            m=l+r+1>>1;
        for(j=i;j<=l;++j)
            o[j]=t;
    }
    for(i=1;i<=n;++i)
        printf("%d\n",o[i]);
    return 0;
}