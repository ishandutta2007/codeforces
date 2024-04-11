#include<stdio.h>
#include<algorithm>
struct node{
    int a,b,w;
    bool operator<(const node &p)const{return w<p.w;}
}e[200002];
int w[200002],f[200002],n,m,top=0;
long long ans[200002],s[200002];
inline int gf(int p){return f[p]==p?p:(f[p]=gf(f[p]));}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
    }std::sort(e+1,e+n);
    for(int i=1;i<=n;i++)f[i]=i,s[i]=1;
    for(int i=1;i<n;i++){
        if(e[i].w!=e[i-1].w){
            w[++top]=e[i].w;
            ans[top]=ans[top-1];
        }int x=gf(e[i].a),y=gf(e[i].b);
        ans[top]=ans[top]-(s[x]-1)*s[x]-(s[y]-1)*s[y]+(s[x]+s[y]-1)*(s[x]+s[y]);
        f[x]=y;s[y]+=s[x];
    }for(int i=1;i<=top;i++)ans[i]/=2;
    while(m--){
        scanf("%d",&n);
        printf("%lld ",ans[std::upper_bound(w+1,w+top+1,n)-w-1]);
    }
}