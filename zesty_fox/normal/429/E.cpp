#include <bits/stdc++.h>

using namespace std;

using ll=long long;
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;

int n,L[N],R[N],h[N];

struct Edge{int to,nxt,id,flg;}e[N*4];
int head[N],deg[N],tot=1;
pii res[N];

void addedge(int x,int y,int id){
    e[++tot]={y,head[x],id,0};
    head[x]=tot,++deg[x];
}

void dfs(int x){
    for(int i=head[x];i;head[x]=i=e[i].nxt){
        if(e[i].flg) continue;
        int y=e[i].to;
        e[i].flg=1,e[i^1].flg=1;
        res[e[i].id]={x,y};dfs(y);
    }
}

vi lsh;
int lim,sum[N];
void discrete(){
    for(int i=1;i<=n;i++) lsh.pb(L[i]),lsh.pb(R[i]);
    sort(lsh.begin(),lsh.end());
    lsh.resize(lim=unique(lsh.begin(),lsh.end())-lsh.begin());
    auto getrk = [&](int x) {return lower_bound(lsh.begin(),lsh.end(),x)-lsh.begin()+1;};
    for(int i=1;i<=n;i++) L[i]=getrk(L[i]),R[i]=getrk(R[i]);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) L[i]=rdi()*2,R[i]=rdi()*2+1;
    discrete();
    
    for(int i=1;i<=n;i++){
        addedge(L[i],R[i],i);
        addedge(R[i],L[i],i);
        sum[L[i]]++,sum[R[i]]--;
    }

    for(int i=1;i<=lim;i++){
        sum[i]+=sum[i-1];
        if(sum[i]&1) addedge(i,i+1,0),addedge(i+1,i,0);
    }
    
    for(int i=1;i<=lim;i++) dfs(i);
    for(int i=1;i<=n;i++)
        putchar((res[i].fi<res[i].se)+'0'),putchar(' ');
    puts("");
    return 0;
}