#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define pb push_back
#define mp make_pair

const int N=200010;

int n,w[N];
vector<pii> e[N];
int res;
double minsum=1e20;

int vis[N];

int siz[N];
void dfs(int x,int fa,int cnt,int &rt){
    siz[x]=1;int maxs=0;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(vis[y]||y==fa) continue;
        dfs(y,x,cnt,rt);
        siz[x]+=siz[y],maxs=max(maxs,siz[y]);
    }
    maxs=max(maxs,cnt-siz[x]);
    if(maxs<=cnt/2) rt=x;
}

double sum[N];
void calc(int x,int fa,int rt,ll dis,double &sum1,double &sum2){
    sum[rt]+=1.5*w[x]*sqrt(dis);
    sum1+=1.5*w[x]*sqrt(dis);
    sum2+=w[x]*pow(dis,1.5);
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y!=fa) calc(y,x,rt,dis+tmp.se,sum1,sum2);
    }
}

void solve(int x,int tot){
    int tmprt;
    dfs(x,0,tot,x);dfs(x,0,tot,tmprt);
    double sum1=0,sum2=0;
    for(auto tmp:e[x]){
        int y=tmp.fi,w=tmp.se;sum[y]=0;
        calc(y,x,y,w,sum1,sum2);
    }
    vis[x]=1;
    if(sum2<minsum) minsum=sum2,res=x;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(vis[y]) continue;
        if(sum1-2*sum[y]<0) return solve(y,siz[y]);
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++) w[i]=rdi();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi(),w=rdi();
        e[x].pb({y,w}),e[y].pb({x,w});
    }
    solve(1,n);
    printf("%d %.8lf\n",res,minsum);
    return 0;
}