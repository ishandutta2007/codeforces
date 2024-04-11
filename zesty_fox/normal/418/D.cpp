#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define rdi read<int>
#define rdll read<ll>

struct FST{
    pii a[3];
    void insert(int x,int val){
        for(int i=0;i<3;i++){
            if(val>a[i].se){
                for(int j=2;j>i;j--) a[j]=a[j-1];
                a[i]=mp(x,val);return;
            }
        }
    }
    int find(){return a[0].se;}
    int find(int ig){
        for(int i=0;i<3;i++){
            if(a[i].fi!=ig) return a[i].se;
        }
        return 0;
    }
    int find(int ig1,int ig2){
        for(int i=0;i<3;i++){
            if(a[i].fi!=ig1&&a[i].fi!=ig2) return a[i].se;
        }
        return 0;
    }
};
const int N=100010;
int n,Q,ans;

int head[N],tot;
struct Edge{int to,nxt;}e[N<<1];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

FST d[N];
int maxd[N];
void dfs1(int x,int fat){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fat) continue;
        dfs1(y,x);
        maxd[x]=max(maxd[x],maxd[y]+1);
        d[x].insert(y,maxd[y]+1);
    }
}

int fa[N][21],maxn[N][21],maxn2[N][21],lg2[N],dep[N];
void init_lg(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
}

void dfs2(int x,int fat){
    fa[x][0]=fat,maxn[x][0]=d[fat].find(x)+1,maxn2[x][0]=d[fat].find(x);
    for(int i=1;i<=lg2[dep[x]];i++){
        fa[x][i]=fa[fa[x][i-1]][i-1];
        maxn[x][i]=max(maxn[x][i-1],maxn[fa[x][i-1]][i-1]+(1<<(i-1)));
        maxn2[x][i]=max(maxn2[x][i-1]+(1<<(i-1)),maxn2[fa[x][i-1]][i-1]);
    }
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fat) continue;
        dep[y]=dep[x]+1;
        dfs2(y,x);
    }
}

int LCA(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=lg2[dep[x]-dep[y]];i>=0;i--){
        if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    }
    if(x==y) return x;
    for(int i=lg2[dep[x]];i>=0;i--){
        if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];
}

int anc(int x,int k){
    for(int i=lg2[k];i>=0;i--){
        if(k>>i&1) x=fa[x][i];
    }
    return x;
}

int query(int x,int k){
    if(k<=0) return -2;
    int res=0,sum=0;
    for(int i=lg2[k];i>=0;i--){
        if(k>>i&1) res=max(res,maxn[x][i]+sum),sum+=(1<<i),x=fa[x][i];
    }
    return res;
}

int query2(int x,int k){
    if(k<=0) return -2;
    int res=0,sum=0;
    for(int i=lg2[k];i>=0;i--){
        if(k>>i&1) sum+=(1<<i),res=max(res,maxn2[x][i]+k-sum),x=fa[x][i];
    }
    return res;
}

int whichson(int x,int dest){
    for(int i=lg2[dep[x]-dep[dest]];i>=0;i--){
        if(dep[fa[x][i]]>dep[dest]) x=fa[x][i];
    }
    return x;
}

int main(){
    n=rdi();init_lg();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y);addedge(y,x);
    }
    dep[0]=-1;
    dfs1(1,0);dfs2(1,0);
    Q=rdi();
    while(Q--){
        int x=rdi(),y=rdi();ans=0;
        if(dep[x]<dep[y]) swap(x,y);
        int lc=LCA(x,y);
        if(lc==y){
            int mid=(dep[x]-dep[y])>>1,xmid=anc(x,mid);
            ans=max(max(max(max(query(x,mid),\
                                maxd[x]),\
                                query2(xmid,dep[x]-dep[y]-mid)),\
                                d[y].find(whichson(x,y))),\
                                query(y,dep[y]));
        }
        else{
            int mid=(dep[x]+dep[y]-dep[lc]*2)>>1,xmid=anc(x,mid);
            if(xmid==lc){
                ans=max(max(max(max(max(query(x,mid-1),\
                                    maxd[x]),\
                                    query(y,mid-1)),\
                                    maxd[y]),\
                                    d[lc].find(whichson(x,lc),whichson(y,lc))+dep[y]-dep[lc]),\
                                    query(lc,dep[lc])+dep[y]-dep[lc]);
            }
            else{
                ans=max(max(max(max(max(max(query(x,mid),\
                                        maxd[x]),\
                                        query2(xmid,dep[xmid]-dep[lc]-1)+1+dep[y]-dep[lc]),\
                                        query(y,dep[y]-dep[lc]-1)),\
                                        maxd[y]),\
                                        d[lc].find(whichson(x,lc),whichson(y,lc))+dep[y]-dep[lc]),\
                                        query(lc,dep[lc])+dep[y]-dep[lc]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}