// LUOGU_RID: 90977389
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

const int N=3e5+10,MOD=998244353;

int n,mx;

i64 pw[N];
void init(){
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*665496236%MOD;
}

struct BIT{
    int sum[N],mx;
    void add(int x,int v){
        for(;x<=mx;x+=(x&(-x))) sum[x]+=v;
    }
    int query(int x){
        int ret=0;
        for(;x;x-=(x&(-x))) ret+=sum[x];
        return ret;
    }
    int query_pos(int s){
        if(!s) return 0;
        int nw=0;
        for(int i=__lg(mx);i>=0;i--)
            if(nw+(1<<i)<=mx&&s>sum[nw+(1<<i)])
                s-=sum[nw+=(1<<i)];
        return nw+1;
    }
}t;
vi a[N];
int vis[N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init();
    for(int i=1;i<=n;i++){
        int l=rdi(),r=rdi();
        mx=max(mx,r),a[l].pb(i),a[r+1].pb(i);
    }
    t.mx=n;i64 ans=0;
    for(int i=0;i<=mx;i++){
        for(auto cur:a[i])
            if(!vis[cur]) vis[cur]=1,t.add(cur,1);
            else vis[cur]=0,t.add(cur,-1);
        int cnt=n-t.query_pos(t.query(n));
        if(cnt==n) continue;
        else if(cnt==n-1) ans+=pw[n-1];
        else{
            ans+=332748118*(pw[cnt]*(MOD+1-pw[n-cnt-2])%MOD+pw[cnt])%MOD;
            ans+=499122177*pw[n-1]%MOD;
        }
    }
    ans=(ans%MOD+MOD)%MOD;
    for(int i=1;i<n;i++) ans=ans*3%MOD;
    cout<<ans<<endl;
    return 0;
}