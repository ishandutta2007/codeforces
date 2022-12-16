#include <bits/stdc++.h>
using namespace std;
const int N=500010;
struct Edge{
    int to,nxt;
}e[N<<1];
int head[N],tot,n,m,cnt[N];
char ch[N];
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

vector<int> d[N];
int dfn[N],ti,f[N],dep[N],siz[N],idd[N];
void dfs(int x,int fa){
    dfn[x]=++ti;idd[ti]=x;
    f[x]=fa;dep[x]=dep[fa]+1;
    d[dep[x]].push_back(dfn[x]);siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}

queue<int> q;
int bfn[N],idb[N];
void bfs(){
    ti=0;q.push(1);
    while(!q.empty()){
        int x=q.front();q.pop();
        bfn[x]=++ti;idb[ti]=x;
        for(int i=head[x];i;i=e[i].nxt){
            int y=e[i].to;
            if(y==f[x]) continue;
            q.push(y);
        }
    }
}

int sum[N];
inline bool check(int x){
    return x==0||x-(x&(-x))==0;
}

inline int ask(int l,int r){return sum[r]^sum[l-1];}
bool query(int x,int y){
    if(dep[x]>y) return true;
    auto itl=lower_bound(d[y].begin(),d[y].end(),dfn[x]);
    if(itl==d[y].end()) return true;
    auto itr=upper_bound(d[y].begin(),d[y].end(),dfn[x]+siz[x]-1);
    if(itr==d[y].begin()) return true;
    return check(ask(bfn[idd[*itl]],bfn[idd[*(itr-1)]]));
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        addedge(i,x);addedge(x,i);
    }
    scanf("%s",ch+1);
    dfs(1,0);bfs();
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]^(1<<(ch[idb[i]]-'a'));
    for(int i=1;i<=n;i++) sort(d[i].begin(),d[i].end());
    while(m--){
        int x,y;scanf("%d%d",&x,&y);
        puts(query(x,y)?"Yes":"No");
    }
    return 0;
}