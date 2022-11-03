#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 5010
#define M N*2

int head[N],nex[M],ver[M],tot;
int n,m,w;
int dis[N][N];

struct node{
    int c,V,P;
}a[N];

vector<node> h;
bool cmp(node a,node b){
    return a.P<b.P;
}

void add(int x,int y){
    ver[++tot]=y;
    nex[tot]=head[x];
    head[x]=tot;
}


int work(int st,int V,int P){
    int l,r,mid,nowV;
    long long nowP;
    l=0;r=n+1;
    while (l<r){
        mid=(l+r)>>1;
        nowP=nowV=0;
        for (int i=1;i<=w;i++){
            if (dis[a[i].c][st]==-1 || dis[a[i].c][st]>mid) continue;
            if (a[i].V+nowV<V){
                nowV+=a[i].V;
                nowP+=(long long)a[i].V*a[i].P;
            }
            else{
                nowP+=(long long)(V-nowV)*a[i].P;
                nowV=V;
                break;
            }
            if (nowP>P) break;
        }
        if (nowV<V || nowP>P) l=mid+1;
        else r=mid;
    }
    if (r==n+1) return -1;
    return r;
}

void bfs(int st){
    if (dis[st][st]!=-1) return ;
    dis[st][st]=0;
    queue<int> q;
    q.push(st);
    while (!q.empty()){
        int x=q.front();
        q.pop();
        for (int i=head[x];i;i=nex[i]){
            if (dis[st][ver[i]]==-1){
                dis[st][ver[i]]=dis[st][x]+1;
                q.push(ver[i]);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    tot=0;
    memset(head,0,sizeof(head));
    for (int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    memset(dis,-1,sizeof(dis));
    scanf("%d",&w);
    for (int i=1;i<=w;i++){
        scanf("%d%d%d",&a[i].c,&a[i].V,&a[i].P);
        bfs(a[i].c);
    }
    sort(a+1,a+w+1,cmp);
    int Q;
    scanf("%d",&Q);
    while (Q--){
        int g,r,a;
        scanf("%d%d%d",&g,&r,&a);
        printf("%d\n",work(g,r,a));
    }
    return 0;
}

/*
 6 4
 4 2
 5 4
 1 2
 3 2
 2
 3 1 2
 3 2 3
 6
 1 2 6
 2 3 7
 3 1 2
 4 3 8
 5 2 5
 6 1 10
*/