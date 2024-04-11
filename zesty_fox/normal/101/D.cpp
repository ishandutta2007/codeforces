#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N=100010;
int n,head[N],tot,siz[N];
ll ans,sum[N];
struct Edge{
    int to,nxt,w;
}e[N<<1];
void addedge(int x,int y,int w){
    e[++tot]=(Edge){y,head[x],w};
    head[x]=tot;
}

bool cmp(int x,int y){
    return 2ll*(sum[e[x].to]+e[x].w)*siz[e[y].to]<2ll*(sum[e[y].to]+e[y].w)*siz[e[x].to];
}

void dfs1(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs1(y,x);
        siz[x]+=siz[y];
        sum[x]+=sum[y]+e[i].w;
    }
}

void dfs(int x,int fa,ll ti){
    ans+=ti;
    vector<int> tmp;
    for(int i=head[x];i;i=e[i].nxt){
        if(e[i].to==fa) continue;
        tmp.push_back(i);
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for(auto i:tmp){
        int y=e[i].to;
        dfs(y,x,ti+e[i].w);
        ti+=2*(sum[y]+e[i].w);
    }
    return;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        addedge(x,y,w);addedge(y,x,w);
    }
    dfs1(1,0);dfs(1,0,0);
    printf("%.10lf\n",1.0*ans/(n-1));
    return 0;
}