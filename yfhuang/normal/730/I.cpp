#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define N 3010
#define M N*6
#define INF 0x3f3f3f3f

int n,p,s;
int P,S,ST,ED;
int head[N],ver[M],edge[M],nex[M],val[M],tot;
int a[N],b[N];
int dis[N],pre[N];
bool v[N];
int maxflow,ans;
int id[N];

void add(int x,int y,int z,int w){
    ver[++tot]=y;
    edge[tot]=z;
    val[tot]=w;
    nex[tot]=head[x];
    head[x]=tot;
}

void make_graph(){
    P=n+1;
    S=n+2;
    ST=n+3;
    ED=n+4;

    tot=1;
    memset(head,0,sizeof(head));
    
    add(ST,P,p,0);
    add(P,ST,0,0);
    
    add(ST,S,s,0);
    add(S,ST,0,0);
    
    for (int i=1;i<=n;i++){
        add(P,i,1,a[i]);
        add(i,P,0,-a[i]);
        
        add(S,i,1,b[i]);
        add(i,S,0,-b[i]);
        
        add(i,ED,1,0);
        add(ED,i,0,0);
    }
}


bool spfa(){
    queue<int> q;
    memset(dis,200,sizeof(dis));
    memset(v,0,sizeof(v));
    dis[ST]=0;
    q.push(ST);
    v[ST]=1;
    
    while (!q.empty()){
        int x=q.front();
        q.pop();
        v[x]=0;
        for (int i=head[x];i;i=nex[i]){
            if (edge[i] && dis[ver[i]]<dis[x]+val[i]){
                dis[ver[i]]=dis[x]+val[i];
                pre[ver[i]]=i;
                if (!v[ver[i]]){
                    v[ver[i]]=1;
                    q.push(ver[i]);
                }
            }
        }
    }
    return dis[ED]>0;
}


void update(){
    int i,x,y;
    
    y=ED;
    do{
        i=pre[y];
        x=ver[i^1];
        edge[i]-=1;
        edge[i^1]+=1;
        y=x;
    }while (x!=ST);
    maxflow+=1;
    ans+=dis[ED];
}

int main(){
    scanf("%d%d%d",&n,&p,&s);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    
    make_graph();
    maxflow=ans=0;
    while (spfa()) update();
    printf("%d\n",ans);
    int top=0;
    for (int i=1;i<=n;i++) if (edge[i*6]==0){
        id[++top]=i;
    }
    for (int i=1;i<=p;i++) printf("%d%c",id[i],i==p?'\n':' ');
    top=0;
    for (int i=1;i<=n;i++) if (edge[i*6+2]==0){
        id[++top]=i;
    }
    for (int i=1;i<=s;i++) printf("%d%c",id[i],i==s?'\n':' ');
    return 0;
}