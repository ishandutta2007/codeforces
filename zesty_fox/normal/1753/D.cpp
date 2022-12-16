#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=3e5+10;

int n,m;
i64 p,q;
char s[N];

inline int id(int x,int y){
    return (x-1)*m+y;
}
inline int id(pii a){
    return (a.fi-1)*m+a.se;
}

const int fx[][2]={{0,1},{0,-1},{1,0},{-1,0}};

vector<pii> e[N];

pii trans(int x1,int y1,char ch,int mul=1){
    switch(ch){
        case 'U': {x1+=mul;break;}
        case 'D': {x1-=mul;break;}
        case 'L': {y1+=mul;break;}
        case 'R': y1-=mul;
    }
    return {x1,y1};
}

bool legal(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=m;
}

void build(){
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            if(s[id(x,y)]=='.'||s[id(x,y)]=='#') continue;
            auto to1=trans(x,y,s[id(x,y)],2);
            if(legal(to1.fi,to1.se)) e[id(to1)].pb({id(x,y),q});
            to1=trans(x,y,s[id(x,y)]);
            for(auto ch:{'L','R','U','D'}){
                if(s[id(x,y)]==ch) continue;
                int x2,y2;tie(x2,y2)=trans(to1.fi,to1.se,ch);
                if(!legal(x2,y2)) continue;
                e[id(x2,y2)].pb({id(x,y),p});
            }
        }
    }
}

int vis[N];
i64 dis[N];
void dij(){
    priority_queue<pair<i64,int>,vector<pair<i64,int>>,greater<pair<i64,int>>> q;
    memset(dis,0x3f,sizeof(dis));
    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
            if(s[id(x,y)]=='.') q.push({dis[id(x,y)]=0,id(x,y)});
    while(!q.empty()){
        int x=q.top().se;q.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for(auto [y,w]:e[x]){
            if(dis[y]>dis[x]+w)
                dis[y]=dis[x]+w,q.push({dis[y],y});
        }
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    p=rdi(),q=rdi();
    for(int i=1;i<=n;i++) scanf("%s",s+(i-1)*m+1);
    build();dij();
    i64 ans=1e18;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=m;y++){
            for(auto ch:{'L','R','U','D'}){
                int x2,y2;tie(x2,y2)=trans(x,y,ch);
                if(x2<1||x2>n||y2<1||y2>m) continue;
                ans=min(ans,dis[id(x,y)]+dis[id(x2,y2)]);
            }
        }
    }
    if(ans>=1e18) puts("-1");
    else cout<<ans<<endl;
    return 0;
}