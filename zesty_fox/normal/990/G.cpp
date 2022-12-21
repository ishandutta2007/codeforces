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
#define pf push_front
#define mp make_pair

const int N=200010;
int n,p[N];
vector<pii> edgelist;
vi edges[N];

vi pr;
int v[N],mu[N];
void init(int lim){
    mu[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,mu[i]=-1,pr.pb(i);}
        for(auto j:pr){
            if(j>v[i]||j>lim/i) break;
            v[j*i]=j;
            if(i%j==0) mu[j*i]=0;
            else mu[j*i]=-mu[i];
        }
    }
}

int gcd(int x,int y){
    return !x?y:gcd(y%x,x);
}

int maxn;
ll f[N],res[N];

int siz[N],fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y,ll &sum){
    x=find(x),y=find(y);
    if(x==y) return;
    if(siz[x]<siz[y]) swap(x,y);
    sum+=(ll)siz[x]*siz[y];
    siz[x]+=siz[y],fa[y]=x;
}

void solve(int i){
    for(auto tmp:edges[i]){
        int x=edgelist[tmp].fi,y=edgelist[tmp].se;
        fa[x]=x,fa[y]=y,siz[x]=siz[y]=1;
    }
    for(auto tmp:edges[i]){
        int x=edgelist[tmp].fi,y=edgelist[tmp].se;
        merge(x,y,f[i]);
    }
}

int main(){
    init(N-10);
    n=rdi();
    for(int i=1;i<=n;i++){
		maxn=max(maxn,p[i]=rdi());
		for(int d=1;d<=p[i]/d;d++){
            if(p[i]%d) continue;
            f[d]++;
            if(p[i]!=d*d) f[p[i]/d]++;
        }
	}
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),gc=gcd(p[x],p[y]);
        edgelist.pb(mp(x,y));
        for(int d=1;d<=gc/d;d++){
            if(gc%d) continue;
            edges[d].pb(i-1);
            if(gc!=d*d) edges[gc/d].pb(i-1);
        }
    }
    for(int i=1;i<=maxn;i++){
		if(f[i]) solve(i);
	}
    for(int i=1;i<=maxn;i++){
        for(int j=i;j<=maxn;j+=i) 
            res[i]+=mu[j/i]*f[j];
    }
    for(int i=1;i<=maxn;i++){
        if(res[i]) printf("%d %lld\n",i,res[i]);
    }
    return 0;
}