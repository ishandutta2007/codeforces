#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
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

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=300010;
ll p[N];
int n,m,x,f[N],siz[N];
unordered_map<int,int> e[N];

int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
int merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y||p[x]+p[y]<::x) return 0;
    if(siz[x]<siz[y]) swap(x,y);
    f[y]=x,p[x]=p[x]+p[y]-::x;
    for(auto tmp:e[y]) 
        if(tmp.fi!=x) e[x].insert(tmp);
    e[y].clear();siz[x]=e[x].size();
    return x;
}

priority_queue<pair<ll,int> > q;
vi res;
int main(){
    n=rdi(),m=rdi(),x=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x][y]=e[y][x]=i;
    }
    for(int i=1;i<=n;i++) f[i]=i,siz[i]=e[i].size(),q.push(mp(p[i],i));
    while(!q.empty()){
        int x=q.top().se;q.pop();
        auto it=e[x].begin();
        for(;it!=e[x].end();){
            auto edge=*it;int y=edge.fi,ret=merge(x,y);
            if(ret){
                q.push(mp(p[ret],ret));
                res.pb(edge.se);break;
            }
            else e[x].erase(it++);
        }
    }
    if(res.size()<n-1) puts("NO");
    else{
        puts("YES");
        for(auto i:res) printf("%d\n",i);
    }
    return 0;
}