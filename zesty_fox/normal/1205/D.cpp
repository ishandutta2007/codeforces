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

const int N=100010,INF=0x3f3f3f3f;
vector<pair<int,ll> > e[N];
int n,siz[N],rt,minx=INF;
void find_zx(int x,int fa){
    siz[x]=1;int mxn=0;
    for(auto tmp:e[x]){    
        int y=tmp.fi;
        if(y==fa) continue;
        find_zx(y,x);
        siz[x]+=siz[y];mxn=max(mxn,siz[y]);
    }
    mxn=max(mxn,n-siz[x]);
    if(mxn<minx) minx=mxn,rt=x;
}

void dfs(int x,int fa){
    siz[x]=1;
    for(auto tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
    }
}

void doit(int x,int fa,ll mul){
    ll sum=0;
    for(auto &tmp:e[x]){
        int y=tmp.fi;
        if(y==fa) continue;
        doit(y,x,mul);
        tmp.se=(sum+1)*mul;
        sum+=siz[y];
    }
}

int main(){
    n=rdi();
    if(n==1) return 0;
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(mp(y,0));e[y].pb(mp(x,0));
    }
    find_zx(1,0);dfs(rt,0);
    sort(e[rt].begin(),e[rt].end(),[&](const pair<int,ll> &x,const pair<int,ll> &y){return siz[x.fi]<siz[y.fi];});
    int p,s=e[rt].size();
    for(int pos=0,sum=0;pos<s;pos++){
        sum+=siz[e[rt][pos].fi];
        if(sum>=(n-1)/3) {p=pos;break;}
    }
    ll sum=0;
    for(int i=0;i<=p;i++){
        int y=e[rt][i].fi;
        doit(y,rt,1);
        e[rt][i].se=sum+1;
        sum+=siz[y];
    }
    ll sizA=sum;sum=0;
    for(int i=p+1;i<s;i++){
        int y=e[rt][i].fi;
        doit(y,rt,sizA+1);
        e[rt][i].se=(sum+1)*(sizA+1);
        sum+=siz[y];
    }
    for(int x=1;x<=n;x++){
        for(auto tmp:e[x]){
            int y=tmp.fi;
            if(tmp.se) printf("%d %d %lld\n",x,y,tmp.se);
        }
    }
    return 0;
}