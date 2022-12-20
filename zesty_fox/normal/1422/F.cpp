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

const int MOD=1e9+7,N=200010,LIM=86;
vector<pii> fac[N];
int v[N],pr[N],pcnt;
void init(int lim=N-10){
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,pr[++pcnt]=i;}
        for(int j=1;j<=pcnt;j++){
            if(pr[j]>v[i]||pr[j]>lim/i) break;
            v[pr[j]*i]=pr[j];
        }
    }
    for(int i=1;i<=pcnt;i++){
        for(ll j=pr[i],cnt=1;j<=lim;j*=pr[i],cnt++){
            for(int k=j;k<=lim;k+=j) fac[k].pb(mp(i,cnt));
        }
    }
}

int n,q,a[N];

inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

namespace ST1{
int8_t mx[LIM+2][N][17];
int lg2[N];
void init(){
    for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=n;i++){
        for(auto tmp:fac[a[i]]){
            if(tmp.fi>LIM) break;
            mx[tmp.fi][i][0]=tmp.se;
        }
    }
    for(int i=1;i<=LIM;i++){
        for(int j=1;j<=lg2[n];j++){
            for(int k=1;k<=n-(1<<j)+1;k++){
                mx[i][k][j]=max(mx[i][k][j-1],mx[i][k+(1<<j-1)][j-1]);
            }
        }
    }
}

inline ll query(int l,int r){
    int k=lg2[r-l+1];
    ll res=1;
    for(int i=1;i<=LIM;i++){
        res*=qpow(pr[i],max(mx[i][l][k],mx[i][r-(1<<k)+1][k]));
        res%=MOD;
    }
    return res;
}
}

namespace ST2{
    #define mid ((l+r)>>1)
    struct Node{
        int ls,rs;ll mul;
        Node(){ls=rs=0,mul=1;}
    }t[N<<5];
    int tot,rt[N<<2];

    int newnode(){return ++tot;}
    void modify(int pre,int &now,int l,int r,int x,ll val){
        t[now=newnode()]=t[pre];
        t[now].mul=t[now].mul*val%MOD;
        if(l==r) return;
        if(x<=mid) modify(t[pre].ls,t[now].ls,l,mid,x,val);
        else modify(t[pre].rs,t[now].rs,mid+1,r,x,val);
    }
    ll query(int now,int l,int r,int x,int y){
        if(!now) return 1;
        if(x<=l&&r<=y) return t[now].mul;
        ll res=1;
        if(x<=mid) res=res*query(t[now].ls,l,mid,x,y)%MOD;
        if(y>mid) res=res*query(t[now].rs,mid+1,r,x,y)%MOD;
        return res;
    }
    void init(){
        int pos[N]={0};
        rt[0]=newnode();
        for(int i=1;i<=n;i++){
            if(!fac[a[i]].size()||fac[a[i]].back().fi<=LIM){
                rt[i*2-1]=rt[i*2]=rt[(i-1)*2];
                continue;
            }
            int maxp=fac[a[i]].back().fi,pre=pos[maxp];
            modify(rt[i*2-2],rt[i*2-1],1,n,pre+1,pr[maxp]);
            if(i+1<=n) modify(rt[i*2-1],rt[i*2],1,n,i+1,qpow(pr[maxp]));
            else rt[i*2]=rt[i*2-1];
            pos[maxp]=i;
        }
    }
}

ll ans;
int main(){
    n=rdi();init();
    for(int i=1;i<=n;i++) a[i]=rdi();
    ST1::init(),ST2::init();
    q=rdi();
    while(q--){
        ll l=rdi(),r=rdi();
        l=(l+ans)%n+1,r=(r+ans)%n+1;
        if(l>r) swap(l,r);
        printf("%lld\n",ans=(ST1::query(l,r)*ST2::query(ST2::rt[r*2],1,n,1,l)%MOD));
    }
    return 0;
}