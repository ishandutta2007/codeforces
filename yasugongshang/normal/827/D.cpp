#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,qwq,cnt;
int fa[200005],ans[200005];
int zx[200005],dep[200005],top[200005],id[200005],son[200005],sz[200005];
int mx[800005],jl[200005],dy[200005],mn[800005];
int tot,head[200005],nx[400005],to[400005],w[400005];
struct node
{
    int fro,to,zhi,id,ff;
}a[200005];
int read()
{
    char ch=getchar();int x=0,ff=1;
    while(ch<'0'||ch>'9') {if(ch=='-') ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
    return ff*x;
}
void write(int z)
{
    if(z<0){putchar('-');z=-z;}
    if(z>=10){write(z/10);}
    putchar(z%10+'0');
}
bool cmp(node aa,node bb)
{
    return aa.zhi<bb.zhi;
}
int getfa(int aa)
{
    return fa[aa]==0?aa:fa[aa]=getfa(fa[aa]);
}
void jia(int aa,int bb,int cc)
{
    tot++;
    nx[tot]=head[aa];
    to[tot]=bb;
    w[tot]=cc;
    head[aa]=tot;
    return;
}
void dfs(int rt,int faa)
{
    sz[rt]=1;
    dep[rt]=dep[faa]+1;
    zx[rt]=faa;
    int mx=0;
    for(int i=head[rt];i;i=nx[i])
    {
        int yy=to[i];
        if(yy==faa) continue;
        dfs(yy,rt);
        jl[yy]=w[i];
        sz[rt]+=sz[yy];
        if(sz[yy]>mx) mx=sz[yy],son[rt]=yy;
    }
    return;
}
void dfs1(int rt)
{
    id[rt]=++cnt;
    dy[cnt]=rt;
    if(son[rt]) top[son[rt]]=top[rt],dfs1(son[rt]);
    for(int i=head[rt];i;i=nx[i])
    {
        int yy=to[i];
        if(yy==zx[rt]||yy==son[rt]) continue;
        top[yy]=yy;
        dfs1(yy);
    }
    return;
}
void up(int rt)
{
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
    return;
}
void push(int rt)
{
    mn[rt<<1]=min(mn[rt],mn[rt<<1]);
    mn[rt<<1|1]=min(mn[rt],mn[rt<<1|1]);
    return;
}
void bt(int rt,int ll,int rr)
{
    mn[rt]=inf;
    if(ll==rr)
    {	
        mx[rt]=jl[dy[ll]];
        return;
    }
    int mid=(ll+rr)>>1;
    bt(rt<<1,ll,mid);
    bt(rt<<1|1,mid+1,rr);
    up(rt);
    return;
}
int chamx(int rt,int ll,int rr,int L,int R,int kk)
{
    if(ll==L&&rr==R) {mn[rt]=min(mn[rt],kk);return mx[rt];}
    int mid=(ll+rr)>>1;push(rt);
    if(R<=mid) return chamx(rt<<1,ll,mid,L,R,kk);
    else if(L>mid) return chamx(rt<<1|1,mid+1,rr,L,R,kk);
    else return max(chamx(rt<<1,ll,mid,L,mid,kk),chamx(rt<<1|1,mid+1,rr,mid+1,R,kk));
}
int chamn(int rt,int ll,int rr,int dd)
{
    if(ll==rr) return mn[rt];
    int mid=(ll+rr)>>1;push(rt);
    if(dd<=mid) return chamn(rt<<1,ll,mid,dd);
    else return chamn(rt<<1|1,mid+1,rr,dd);
}
int query(int x,int y,int zhi)
{
    int X=top[x],Y=top[y],ans=0;
    while(X!=Y)
    {
        if(dep[X]>dep[Y])
        {
            ans=max(ans,chamx(1,1,n,id[X],id[x],zhi));
            x=zx[X],X=top[x];
        }
        else
        {
            ans=max(ans,chamx(1,1,n,id[Y],id[y],zhi));
            y=zx[Y],Y=top[y];
        }
    }
    if(x!=y) 
    {
        if(dep[x]>dep[y]) swap(x,y);
        ans=max(ans,chamx(1,1,n,id[x]+1,id[y],zhi));
    }
    return ans;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;++i) 
    {
        a[i].fro=read();
        a[i].to=read();
        a[i].zhi=read();
        a[i].id=i;
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;++i)
    {
        int X=getfa(a[i].fro),Y=getfa(a[i].to);
        if(X!=Y) fa[X]=Y,jia(a[i].fro,a[i].to,a[i].zhi),jia(a[i].to,a[i].fro,a[i].zhi),a[i].ff=1;
    }
    dfs(1,1);
    top[1]=1;
    dfs1(1);
    bt(1,1,n);
    for(int i=1;i<=m;++i)
    if(!a[i].ff) ans[a[i].id]=query(a[i].fro,a[i].to,a[i].zhi)-1;
    for(int i=1;i<=m;++i)
    if(a[i].ff) ans[a[i].id]=chamn(1,1,n,max(id[a[i].to],id[a[i].fro]))-1;
    for(int i=1;i<=m;++i) if(ans[i]==inf-1) write(-1),putchar(' ');else write(ans[i]),putchar(' ');
    return 0;
}