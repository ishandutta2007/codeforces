#include <iostream>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <vector>
#include <set>
#include <queue>

#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
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

const int INF=0x3f3f3f3f;
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

const int N=400010,MOD=1e9+7;
int n;
struct Edge{int to,nxt;}e[N<<1];
int head[N],tot=1;
void addedge(int x,int y){
    e[++tot]=(Edge){y,head[x]};
    head[x]=tot;
}

inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

int vis[N],st[N],tp,loop[N],cnt,bel[N];
void dfs(int x,int in){
    if(vis[x]||bel[x]) return;
    st[++tp]=x;vis[x]=1;
    for(int i=head[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(i==(in^1)||bel[y]) continue;
        if(vis[y]){
            ++cnt;
            vis[st[tp]]=1,loop[cnt]++;
            bel[st[tp]]=cnt;
            while(tp){
                tp--;
                vis[st[tp]]=1;
                bel[st[tp]]=cnt;
                loop[cnt]++;
                if(st[tp]==y) break;
            }
            return;
        }
        else dfs(y,i);
    }
    tp--;
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        int x=rdi();
        addedge(i,x);addedge(x,i);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            tp=0;
            dfs(i,-1);
        }
    }
    ll ans=1,sum=0;
    for(int i=1;i<=cnt;i++){
        sum+=loop[i];
        ans=ans*(qpow(2,loop[i])-2)%MOD;
    }
    printf("%lld\n",ans*qpow(2,n-sum)%MOD);
    return 0;
}