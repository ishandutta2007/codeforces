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

const int N=1010;

vi e[N];

pii query(const vector<int> &nodes){
    printf("? %lu ",nodes.size());
    for(auto x:nodes) printf("%d ",x);
    cout<<endl;
    int x=rdi(),d=rdi();
    return mp(x,d);
}

void print_ans(int x,int y){
    printf("! %d %d",x,y);cout<<endl;
    scanf("%*s");
}

int n,rt,fr,to,mindis;

vi d[N];
void dfs(int x,int fa,int dep){
    d[dep].pb(x);
    for(auto y:e[x]){
        if(y==fa) continue;
        dfs(y,x,dep+1);
    }
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<n;i++){
        int x=rdi(),y=rdi();
        e[x].pb(y),e[y].pb(x);
    }

    vi tmp(n);iota(tmp.begin(),tmp.end(),1);
    auto _=query(tmp);rt=_.fi,mindis=_.se;
    
    for(int i=0;i<n;i++) d[i].clear();
    dfs(rt,0,0);
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(d[mid].empty()) {r=mid-1;continue;}
        auto tmp=query(d[mid]);
        if(tmp.se==mindis) fr=tmp.fi,l=mid;
        else r=mid-1;
    }
    
    for(int i=0;i<n;i++) d[i].clear();
    dfs(fr,0,0);to=query(d[mindis]).fi;
    
    print_ans(fr,to);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}