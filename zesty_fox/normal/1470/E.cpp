#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=100010,K=5;

int n,k,q,p[N];
ll f[N][K],sum[N][K];
vector<int8_t> seq[N];
ll g[N][K];

int lg2(int x) {return !x?-1:__lg(x);}

void init(){
    for(int i=0;i<=k;i++) f[n+1][i]=1;
    for(int i=n;i>=1;i--)
        for(int j=0;j<=k;j++){
            f[i][j]=0;
            for(int l=0;l<=min(j,n-i);l++) f[i][j]+=f[i+l+1][j-l];
        }
    for(int i=1;i<=n;i++){
        seq[i].resize(min(n-i,k)+1);
        iota(seq[i].begin(),seq[i].end(),0);
        sort(seq[i].begin(),seq[i].end(),[&](const int &x,const int &y){
            return p[i+x]<p[i+y];
        });
        for(int j=0;j<(int)seq[i].size();j++){
            int now=seq[i][j];
            sum[i][now]=(j?sum[i][seq[i][j-1]]:0)+f[i][now];
        }
    }   
    for(int j=0;j<=k;j++){
        g[n+1][j]=0;
        for(int i=n;i>=1;i--){
            g[i][j]=g[i+1][j];
            for(auto cur:seq[i]){
                if(!cur) break;
                if(cur>j||i+cur>n) continue;
                g[i][j]+=f[i+cur+1][j-cur];
            }
        }
    }
}

ll query(int l,int r,int k) {return g[l][k]-g[r][k];}

int query(int x,ll rk,int k,int pos){
    if(x>n) return -1;
    int l=x,r=n+1;
    while(l<r){
        int mid=(l+r+1)/2;
        ll tmp=query(x,mid,k);
        if(tmp<rk&&tmp+f[mid][k]>=rk) l=mid;
        else r=mid-1;
    }
    if(l==x){
        for(auto cur:seq[x]){
            if(cur>k) continue;
            int nxt=x+cur+1;
            ll tmp=f[nxt][k-cur];
            if(rk>tmp) rk-=tmp;
            else{
                if(x<=pos&&pos<nxt) return p[x+nxt-pos-1];
                else return query(nxt,rk,k-cur,pos);
            }
        }
    }
    else{
        int nxt=l;
        if(x<=pos&&pos<nxt) return p[pos];
        else return query(nxt,rk-query(x,nxt,k),k,pos);
    }
    return -1;
}

void solve(){
    n=rdi(),k=rdi(),q=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    init();
    while(q--){
        int y=rdi();ll x=rdll();
        cout<<query(1,x,k,y)<<'\n';
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}