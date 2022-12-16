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
#define mp make_pair
#define pb push_back

const int MAXN=10000010,N=200010,INF=0x3f3f3f3f;

int pr[MAXN],pcnt,v[MAXN],id[MAXN];
void init(int lim){
    v[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,pr[++pcnt]=i;}
        for(int j=1;j<=pcnt;j++){
            if(pr[j]>v[i]||pr[j]>lim/i) break;
            v[pr[j]*i]=pr[j];
        }
    }
    for(int i=1;i<=pcnt;i++) id[pr[i]]=i;
}

int frac(int x){
    for(int i=1;pr[i]<=x/pr[i];i++){
        if(x%pr[i]==0){
            while(x%pr[i]==0&&(x/pr[i]%pr[i]==0)) x/=pr[i],x/=pr[i];
        }
    }
    return x;
}

namespace SegTree{
#define mid ((l+r)>>1)
struct Node{int ls,rs,sum;}t[N*24];
int rt[N],tot;
void init(int n){
    for(int i=0;i<=n;i++) rt[i]=0;
    t[0]={0,0,0};
    tot=0;
}

int newnode(){
    t[++tot]={0,0,0};
    return tot;
}

void add(int &now,int pre,int l,int r,int x,int val){
    now=newnode();
    t[now]=t[pre],t[now].sum+=val;
    if(l==x&&r==x) return;
    if(x<=mid) add(t[now].ls,t[pre].ls,l,mid,x,val);
    else add(t[now].rs,t[pre].rs,mid+1,r,x,val);
}

int query(int now,int l,int r,int lim){
    if(l==r) return l;
    if(lim<=t[t[now].ls].sum) return query(t[now].ls,l,mid,lim);
    else return query(t[now].rs,mid+1,r,lim-t[t[now].ls].sum);
}

int query_sum(int now,int l,int r,int x,int y){
    if(!now) return 0;
    if(x<=l&&r<=y) return t[now].sum;
    int res=0;
    if(x<=mid) res+=query_sum(t[now].ls,l,mid,x,y);
    if(y>mid) res+=query_sum(t[now].rs,mid+1,r,x,y);
    return res;
}
#undef mid
}

int n,k,a[N],pre[N],nosq[N],pos[MAXN],f[N][21],g[N][21],rt[N],ans;
vi pres[N];

void clear(){
    SegTree::init(n);
    for(int i=0;i<=n+1;i++){
        pos[nosq[i]]=rt[i]=pre[i]=0,pres[i].clear();
        for(int j=0;j<=k;j++) f[i][j]=INF,g[i][j]=0;
    }
    for(int j=0;j<=k;j++) f[1][j]=0;
}

void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),nosq[i]=frac(a[i]);
    clear();
    
    for(int i=1;i<=n;i++) pre[i]=pos[nosq[i]],pos[nosq[i]]=i;

    {
        int cur=0;
        for(int i=1;i<=n;i++) pres[pre[i]].pb(i);
        for(int i=n-1;i>=0;i--){
            for(auto x:pres[i]) 
                SegTree::add(SegTree::rt[cur+1],SegTree::rt[cur],1,n+1,x,1),cur++;
            rt[i]=SegTree::rt[cur];
        }
    }
    
    {
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++) g[i][j]=SegTree::query(rt[i],1,n+1,j+1)-1;
        }
    }
    
    {
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<=k-j;l++){
                    int nxt=g[i][l];
                    f[nxt+1][j+l]=min(f[nxt+1][j+l],f[i][j]+1);
                }
            }
        }
    }
    ans=INF;
    for(int i=0;i<=k;i++) ans=min(ans,f[n+1][i]);
    printf("%d\n",ans);
}

int T;
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    T=rdi();init(MAXN-10);
    while(T--) solve();
    return 0;
}