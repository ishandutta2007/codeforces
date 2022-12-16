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

const int N=500010,INF=0x3f3f3f3f;

struct Edge{int to,nxt;}e[N<<1];
int head[N],tot;
void addedge(int x,int y){
    e[++tot]={y,head[x]};
    head[x]=tot;
}

int n;

int siz[N];
void find_cen(int x,int fa,vi &rt,int &min_siz){
    siz[x]=1;int now_siz=0;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        find_cen(y,x,rt,min_siz);
        siz[x]+=siz[y];
        now_siz=max(now_siz,siz[y]);
    }
    now_siz=max(now_siz,n-siz[x]);
    if(now_siz<min_siz) min_siz=now_siz,rt={x};
    else if(now_siz==min_siz) rt.pb(x);
}

pii find_leaf(int x,int fa){
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa) continue;
        return find_leaf(y,x);
    }
    return mp(x,fa);
}

vi rt;
void solve(){
    n=rdi();

    memset(head,0,sizeof(int)*(n+2));
    tot=0;

    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        addedge(x,y),addedge(y,x);
    }

    int max_siz=INF;rt.clear();
    find_cen(1,0,rt,max_siz);

    if(rt.size()<2) return (void)printf("1 %d\n1 %d\n",e[head[1]].to,e[head[1]].to);
    auto tmp=find_leaf(rt[0],rt[1]);
    printf("%d %d\n%d %d\n",tmp.fi,tmp.se,tmp.fi,rt[1]);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}