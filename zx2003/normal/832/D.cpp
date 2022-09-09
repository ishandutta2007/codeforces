//#pragma GCC optimize("O2")
#include <cstdio>
#include <cctype>
#include <cstring>
typedef int LL;
int n,m,r,i,x,y,z,c[100010],xb;
struct node{
    LL sum,gg,lc,rc,l,r;
}a[410000];
void pushdown(LL i){
    if(a[i].gg){
        a[i].sum+=(a[i].r-a[i].l+1)*a[i].gg;
        if(!a[i].lc)a[i].lc=++xb,a[a[i].lc].l=a[i].l,a[a[i].lc].r=(a[i].l+a[i].r)>>1;
        if(!a[i].rc)a[i].rc=++xb,a[a[i].rc].l=a[a[i].lc].r+1,a[a[i].rc].r=a[i].r;
        a[a[i].lc].gg+=a[i].gg;
        a[a[i].rc].gg+=a[i].gg;
        a[i].gg=0;
    }
}
void merge(int i){
	pushdown(a[i].lc);
	pushdown(a[i].rc);
    a[i].sum=a[a[i].lc].sum+a[a[i].rc].sum;
}
void add(int&i,int l,int r,int rl,int rr,LL x){
	if(!i)i=++xb,a[i].l=rl,a[i].r=rr;
    if(rl==l && rr==r){
        a[i].gg+=x;
        return;
    }
    pushdown(i);
    int m=(rl+rr)>>1;
    if(l>m)add(a[i].rc,l,r,m+1,rr,x);
        else if(r<=m)add(a[i].lc,l,r,rl,m,x);
                else{
                    add(a[i].lc,l,m,rl,m,x);
                    add(a[i].rc,m+1,r,m+1,rr,x);
                }
    merge(i);
}
LL sum(int i,int l,int r,int rl,int rr){
	if(!i)return 0;
    if(rl==l && rr==r)return a[i].gg*(r-l+1)+a[i].sum;
    pushdown(i);
    int m=(rl+rr)>>1;
    if(l>m)return sum(a[i].rc,l,r,m+1,rr);
        else if(r<=m)return sum(a[i].lc,l,r,rl,m);
                else return sum(a[i].lc,l,m,rl,m)+sum(a[i].rc,m+1,r,m+1,rr);
}
inline void swap(int&x,int&y){
    int t=x;
    x=y;
    y=t;
}
struct edge{
    int to,next;
    edge(int _to=0,int _next=0):to(_to),next(_next){}
};
struct tree{
    static const int maxn=500010;
    edge e[maxn<<1];
    int n,xb,h[maxn],size[maxn],dep[maxn],dad[maxn],ma[maxn],top[maxn],id[maxn],root,right[maxn],len[maxn];
	int rt[maxn];
    void init(int x,int s){
        n=x;
        root=s;
        xb=0;
        memset(h,0,sizeof h);
        memset(size,0,sizeof size);
        memset(dep,0,sizeof dep);
        memset(dad,0,sizeof dad);
        memset(ma,0,sizeof ma);
        memset(top,0,sizeof top);
    }
    void prepare(){ 
        xb=0;      
        dep[root]=1;
        dfs1(root);
        top[root]=root;
        dfs2(root);
    }
    void addedge(int x,int y){
        e[++xb]=edge(y,h[x]);
        h[x]=xb;
        e[++xb]=edge(x,h[y]);
        h[y]=xb;
    }
    void dfs1(int x){
        int max=0;
        size[x]=1;
        for(int i=h[x];i;i=e[i].next){
            int y=e[i].to;
            if(!dep[y]){
                dad[y]=x;
                dep[y]=dep[x]+1;
                dfs1(y);
                size[x]+=size[y];
                if(size[y]>max){
                    max=size[y];
                    ma[x]=y;
                }
            }
        }
    }
    void dfs2(int x){
        id[x]=++xb;
        if(!ma[x]){
            right[x]=xb;
            len[x]=1;
            return;
        }
        top[ma[x]]=top[x];
        dfs2(ma[x]);
        len[x]=len[ma[x]]+1;
        for(int i=h[x];i;i=e[i].next){
            int t=e[i].to;
            if(dep[t]==dep[x]+1 && t!=ma[x]){
                top[t]=t;
                dfs2(t);
            }
        }
        right[x]=xb;
    }
    int lca(int u,int v){
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            v=dad[top[v]];
        }
        if(dep[u]>dep[v])return v;
            else return u;
    }
    void addline(int u,int v,int x){
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            add(rt[top[v]],1,id[v]-id[top[v]]+1,1,len[top[v]],x);
            v=dad[top[v]];            
        }
        if(dep[u]>dep[v])swap(u,v);
        add(rt[top[u]],id[u]-id[top[u]]+1,id[v]-id[top[u]]+1,1,len[top[u]],x);
    }
    int sumline(int u,int v){
        int ans=0;
        while(top[u]!=top[v]){
            if(dep[top[u]]>dep[top[v]])swap(u,v);
            ans+=sum(rt[top[v]],1,id[v]-id[top[v]]+1,1,len[top[v]]);
            v=dad[top[v]];            
        }
        if(dep[u]>dep[v])swap(u,v);
        ans+=sum(rt[top[u]],id[u]-id[top[u]]+1,id[v]-id[top[v]]+1,1,len[top[u]]);
        return ans;
    }
}g;
int getint(){
    char c=getchar();
    int x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){
        x=(x<<3)+(x<<1)+c-48;
        c=getchar();
    }
    return x;
}
int buf[10];
void putint(int x){
    if(x==0){
        putchar('0');
        return;
    }
    int p=0;
    if(x<0){
        putchar('-');
        x=-x;
    }
    while(x){
        buf[p++]=x % 10;
        x/=10;
    }
    for(int j=p-1;j>=0;j--)putchar(48+buf[j]);
}
inline int calc(int x,int y,int z){
	g.addline(x,y,1);
	int ans=g.sumline(x,z);
	g.addline(x,y,-1);
	return ans;
}
inline void up(int&a,int b){
	if(a<b)a=b;
}
int main(){
    n=getint();
    m=getint();
    g.init(n,1);
    for(i=2;i<=n;++i){
        x=getint();
        g.addedge(x,i);
    }
    g.prepare();
    while(m--){
    	x=getint();
    	y=getint();
    	z=getint();
    	int ans=calc(x,y,z);
    	up(ans,calc(y,x,z));
    	up(ans,calc(z,x,y));
    	putint(ans);
    	putchar('\n');
    }
    return 0;
}