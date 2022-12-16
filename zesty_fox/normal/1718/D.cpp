#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=3e5+10,INF=0x3f3f3f3f;

int n,q,p[N],a[N],b[N];

int ch[N][2],rt;
void build(int *a,int n){
    static int st[N];
    int tp=0;rt=0;
    for(int i=1;i<=n;i++){
        ch[i][0]=ch[i][1]=0;
        while(tp&&a[st[tp]]<a[i]) --tp;
        if(tp) ch[i][0]=ch[st[tp]][1],ch[st[tp]][1]=i;
        else ch[i][0]=rt,rt=i;
        st[++tp]=i;
    }
}

int k;
pii lim[N];
void dfs(int x,int fa){
    if(!x) return;
    lim[x].se=lim[fa].se,lim[x].fi=0;
    if(a[x]) lim[x].se=min(lim[x].se,a[x]),lim[x].fi=a[x];
    for(int i:{0,1})
        dfs(ch[x][i],x),lim[x].fi=max(lim[x].fi,lim[ch[x][i]].fi);
}

int L,R;
void calc(){
    bool flg=1;
    for(int i=1;i<=n;i++) flg&=(lim[i].fi<=lim[i].se);
    if(!flg) {L=1,R=0;return;}
    int tot=0;L=0,R=INF;
    for(int i=1;i<=n;i++) if(!a[i]) swap(lim[i],lim[++tot]);
    sort(lim+1,lim+tot+1,[&](pii a,pii b){return a.se<b.se;});
    set<int> s(b+1,b+k);int c=0;
    for(int i=1;i<=tot;i++){
        auto it=s.upper_bound(lim[i].fi);
        if(it==s.end()||*it>=lim[i].se)
            ++c,R=min(R,lim[i].se-1);
        else s.erase(it);
    }
    if(c>1) {L=1,R=0;return;}
    sort(lim+1,lim+tot+1,[&](pii a,pii b){return a.fi<b.fi;});
    s=set<int>(b+1,b+k),c=0;
    for(int i=tot;i>=1;i--){
        auto it=s.lower_bound(lim[i].se);
        if(it==s.begin()||*prev(it)<=lim[i].fi)
            ++c,L=max(L,lim[i].fi+1);
        else s.erase(prev(it));
    }
    if(c>1) {L=1,R=0;return;}
}

void init(){
    n=rdi(),q=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi();
    k=0;
    for(int i=1;i<=n;i++) a[i]=rdi(),k+=(!a[i]);
    for(int i=1;i<k;i++) b[i]=rdi();
    build(p,n);
    lim[0]={0,INF},dfs(rt,0);
}

void solve(){
    init();
    calc();
    while(q--){
        int d=rdi();
        puts(L<=d&&d<=R?"YES":"NO");
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