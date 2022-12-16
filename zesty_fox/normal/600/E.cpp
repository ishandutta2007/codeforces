#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=100010;

struct Edge{int to,nxt;}e[N<<1];
int n,c[N],head[N],tot;
void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

int siz[N],son[N];
void dfs1(int x,int fa){
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        dfs1(y,x);
        siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
}

int cnt[N],maxn;
ll maxsum;
void insert(int x){
    cnt[c[x]]++;
    if(cnt[c[x]]>maxn) maxn=cnt[c[x]],maxsum=c[x];
    else if(cnt[c[x]]==maxn) maxsum+=c[x];
}

void clear(int x,int fa){
    cnt[c[x]]--;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        clear(y,x);
    }
    maxn=0,maxsum=0;
}

void add(int x,int fa){
    insert(x);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        add(y,x);
    }
}

ll res[N];
void dfs(int x,int fa,bool rsv){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa||y==son[x]) continue;
        dfs(y,x,false);
    }

    if(son[x]) dfs(son[x],x,true);
    
    insert(x);
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa||y==son[x]) continue;
        add(y,x);
    }

    res[x]=maxsum;
    if(!rsv) clear(x,fa);
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++) c[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
    } 
    dfs1(1,0);
    dfs(1,0,0);
    for(int i=1;i<=n;i++) printf("%lld ",res[i]);
    puts("");
    return 0;
}