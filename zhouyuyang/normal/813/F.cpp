#include<iostream>
#include<cstdio>
#include<map>
#define N 500005
using namespace std;
int n,m,T,fa[N],top,st[N<<2],a[N];
struct E{int x,y,l,r;}e[N];
int Getfa(int x){
    while (fa[x]!=x) x=fa[x];
    return x;
}
int col(int x){
    int now=0;
    while (fa[x]!=x) now^=a[x],x=fa[x];
    return now;
}
void link(int x,int y,int D){
    fa[x]=y;a[x]=D;st[++top]=x;
}
void RE(int t){
    for (;top>t;top--)
           fa[st[top]]=st[top],a[st[top]]=0;
}
void work(int l,int r,int k){
    int mid=(l+r)>>1,now=top;
    for (int i=1;i<=k;i++)
        if (e[i].l<=l&&r<=e[i].r){
            int u=Getfa(e[i].x),v=Getfa(e[i].y);
            if (u!=v) link(u,v,col(e[i].x)==col(e[i].y));
            else if (col(e[i].x)==col(e[i].y))
            {
                for(int i=l;i<=r;i++)puts("NO");
                RE(now);return;
            }
            swap(e[k--],e[i--]);
        }
    if (l==r) puts("YES");
    else{
        int i,j;
        for (i=1,j=0;i<=k;i++)
            if(e[i].l<=mid)swap(e[i],e[++j]);
        work(l,mid,j);
        for (i=1,j=0;i<=k;i++)
            if(e[i].r>mid)swap(e[i],e[++j]);
        work(mid+1,r,j);
    }
    RE(now);
}
map<int,int>M[N];
int main(){
    scanf("%d%d",&n,&T);
    for (int i=1;i<=T;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);
        if (M[x][y]) e[M[x][y]].r=i-1,M[x][y]=0;
        else
        {
            M[x][y]=++m;
            e[m].x=x;e[m].y=y;e[m].l=i-1;e[m].r=T;
        }
    }
    for (int i=1;i<=m;i++)
        ++e[i].l;
    for (int i=1;i<=n;i++)fa[i]=i;
    work(1,T,m);
    return 0;
}