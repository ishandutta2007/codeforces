#include<cstdio>
#include<algorithm>
using namespace std;
const int N=3e4+5;
int v[N<<1],head[N],nxt[N<<1],tot;
int vq[N<<1],nxtq[N<<1],headq[N],w[N<<1],totq;
int f[N],las[N],fa[N],dis[N],d[N],tag[N],ans[N],w2[N],w3[N],w4[N];
int vis1[N],vis2[N];
int n,m,cnt,flag,ansn,tht,endd,sta,turn,tot4;
struct edge{
    int x,y,id,lca;
}a[N],b[N],c[N];
inline int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline int getf1(int x){return f[x]==x?x:f[x]=getf1(f[x]);}
inline void merge(int x,int y){
    int f1=getf(x),f2=getf(y);
    fa[f1]=f2;
}
inline void add(int x,int y,int z){
    v[++tot]=y;w4[tot]=z;
    nxt[tot]=head[x];
    head[x]=tot;
}
inline void addq(int x,int y,int z){
    vq[++totq]=y;w[totq]=z;
    nxtq[totq]=headq[x];
    headq[x]=totq;
}
inline void tarjan(int x){
    f[x]=x;vis1[x]=x;
    for(int i=head[x];i;i=nxt[i]){
        int y=v[i];
        if(!f[y]){
            dis[y]=dis[x]+1;
            w3[y]=w4[i];
            w2[y]=w[i];
            tarjan(y);
            f[y]=x;
            las[y]=x;
        }
    }
    for(int i=headq[x];i;i=nxtq[i]){
        int y=vq[i],c=w[i];
        if(f[y])b[c].lca=getf1(y);
    }
}
inline void dfs(int x,int fa){
    vis2[x]=1;
    for(int i=head[x];i;i=nxt[i]){
        int y=v[i];
        if(y!=fa){
            dfs(y,x);
            d[x]+=d[y];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)scanf("%d%d",&a[i].x,&a[i].y),a[i].id=i;
    for(int i=1;i<=n;++i)fa[i]=i;
    for(int i=1;i<=m;++i){
        int x=a[i].x,y=a[i].y;
        if(getf(x)!=getf(y)){//
            merge(x,y);
            add(x,y,i);add(y,x,i);
        }
        else{
            b[++cnt].x=x;b[cnt].y=y;
            b[cnt].id=a[i].id;
            addq(x,y,cnt);addq(y,x,cnt);
        }
    }
    for(int i=1;i<=n;++i)if(!vis1[i])tarjan(i);//tarjanlca,dis
    for(int i=1;i<=cnt;++i){
        int x=b[i].x,y=b[i].y,p=b[i].lca,delta=1,curd;
        curd=dis[x]+dis[y]-2*dis[p];
        if(curd&1)delta=-1;//
        else {
            flag++;endd=y;
            sta=x;turn=p;tht=b[i].id;
        }//
        d[x]+=delta;d[y]+=delta;d[p]-=2*delta;//
    }
    for(int i=1;i<=n;++i)if(!vis2[i])dfs(i,i);//d
    if(!flag){//
        printf("%d\n",m);
        if(m){
            for(int i=1;i<m;++i)printf("%d ",i);
            printf("%d\n",m);
        }
    }
    else if(flag==1){//
        int tot3=0;
        for(int i=endd;i!=turn;i=las[i]){
            if(d[i]==1)//
            ans[++tot3]=w3[i];
        }
        for(int i=sta;i!=turn;i=las[i]){
            if(d[i]==1)//
            ans[++tot3]=w3[i];
        }
        ans[++tot3]=tht;//
        sort(ans+1,ans+1+tot3);
        printf("%d\n",tot3);
        if(tot3){
            for(int i=1;i<tot3;++i)printf("%d ",ans[i]);
            printf("%d\n",ans[tot3]);
        }
    }
    else{//
        for(int i=1;i<=n;++i)if(d[i]==flag)ans[++tot4]=w3[i];
        sort(ans+1,ans+1+tot4);
        printf("%d\n",tot4);
        if(tot4){
            for(int i=1;i<tot4;++i)printf("%d ",ans[i]);
            printf("%d\n",ans[tot4]);
        }
    }
    return 0;
}