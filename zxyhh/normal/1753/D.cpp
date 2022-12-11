#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void solve() ;
int main() {
    // int T;
    // T=rd();
    // for(int i=1;i<=T;i++) {
    //     solve();
    // }
    solve();
}
#define maxn 300005
#define mod 998244353
std::vector<char> s[maxn];
int n,m;
std::vector< std::pair<int,int> > G[maxn];
void addedge(int u,int v,int w) {
    // printf("%d %d %d\n",u,v,w);
    G[v].push_back(std::make_pair(u,w));
    // G[v].push_back(std::make_pair(u,w));
}
inline bool col(int u,int v) {return (u+v)%2;}
inline int id(int u,int v) {return (u-1)*m+v;}
inline bool in(int u,int v) {return u>=1&&u<=n&&v>=1&&v<=m&&s[u][v]!='#';}
int p,q;
ll dis1[maxn],dis2[maxn];
bool vis[maxn];
int S,T;
void dijkstra(ll *dis) {
    for(int i=1;i<=n*m+2;i++) {
        dis[i]=1e18;
    }
    memset(vis,0,sizeof vis);
    std::priority_queue< std::pair<ll,int> ,std::vector<std::pair<ll,int> > ,std::greater< std::pair<ll,int> > > que;
    dis[S]=0;
    que.push(std::make_pair(0,S));
    while(!que.empty()) {
        int now=que.top().second;
        que.pop();
        if (vis[now]) continue;
        vis[now]=1;
        for(auto i:G[now]) {
            if (dis[i.first]>i.second+dis[now]) {
                dis[i.first]=i.second+dis[now];
                que.push(std::make_pair(dis[i.first],i.first));
            }
        }
    }
}
void solve() {
    // freopen("test.out","w",stdout);
    n=rd(),m=rd();
    p=rd(),q=rd();
    for(int i=1;i<=n;i++) {
        s[i].resize(m+2);
        scanf("%s",s[i].begin());
    }
    for(int i=1;i<=n;i++) {
        for(int j=m;j;j--) {
            s[i][j]=s[i][j-1];
        }
    }
    S=n*m+1,T=n*m+2;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (s[i][j]=='.') {
                if (col(i,j)==0) addedge(S,id(i,j),0),addedge(id(i,j),S,0);
                else addedge(id(i,j),T,0),addedge(T,id(i,j),0);
            }
            else {
                if (s[i][j]=='L') {
                    if (in(i+1,j+1)) addedge(id(i,j),id(i+1,j+1),p);
                    if (in(i-1,j+1)) addedge(id(i,j),id(i-1,j+1),p);
                    if (in(i,j+2)) addedge(id(i,j),id(i,j+2),q);
                }
                if (s[i][j]=='R') {
                    if (in(i+1,j-1)) addedge(id(i,j),id(i+1,j-1),p);
                    if (in(i-1,j-1)) addedge(id(i,j),id(i-1,j-1),p);
                    if (in(i,j-2)) addedge(id(i,j),id(i,j-2),q);
                }
                if (s[i][j]=='U') {
                    if (in(i+1,j+1)) addedge(id(i,j),id(i+1,j+1),p);
                    if (in(i+1,j-1)) addedge(id(i,j),id(i+1,j-1),p);
                    if (in(i+2,j)) addedge(id(i,j),id(i+2,j),q);
                }
                if (s[i][j]=='D') {
                    if (in(i-1,j+1)) addedge(id(i,j),id(i-1,j+1),p);
                    if (in(i-1,j-1)) addedge(id(i,j),id(i-1,j-1),p);
                    if (in(i-2,j)) addedge(id(i,j),id(i-2,j),q);
                }
            }
        }
    }
    dijkstra(dis1);
    std::swap(S,T);
    dijkstra(dis2);
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         printf("%lld ",dis2[id(i,j)]);
    //     }
    //     putchar('\n');
    // }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=m;j++) {
    //         printf("%lld ",dis1[id(i,j)]);
    //     }
    //     putchar('\n');
    // }
    // printf("%d %lld\n",col(1,3),dis1[id(1,3)]+dis2[id(2,3)]);
    ll ans=1e15;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if (col(i,j)==0) {
                if (in(i,j+1)) ans=std::min(ans,dis1[id(i,j)]+dis2[id(i,j+1)]);
                if (in(i+1,j)) ans=std::min(ans,dis1[id(i,j)]+dis2[id(i+1,j)]);
                
            }
            else {
                if (in(i,j+1)) ans=std::min(ans,dis2[id(i,j)]+dis1[id(i,j+1)]);
                if (in(i+1,j)) ans=std::min(ans,dis2[id(i,j)]+dis1[id(i+1,j)]);
            }
        }
    }
    if (ans>=1e15) {
        printf("-1\n");
        return ;
    }
    printf("%lld\n",ans);

}