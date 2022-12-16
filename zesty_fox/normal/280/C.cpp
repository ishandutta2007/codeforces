#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100010;
struct Edge{int to,nxt;}e[N<<1];
int head[N],tot,n,dep[N];double ans;
void addedge(int x,int y){e[++tot]=(Edge){y,head[x]};head[x]=tot;}
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;ans+=1.0/dep[x];
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;if(y==fa) continue;
        dfs(y,x);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){int x,y;scanf("%d%d",&x,&y);addedge(x,y);addedge(y,x);}
    dfs(1,0);
    return printf("%.6lf\n",ans),0;
}