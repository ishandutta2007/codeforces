// LUOGU_RID: 94945591
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

template<typename T>
void ckmin(T &a,const T &b) {a=min(a,b);}

const int K=19,N=(1<<K)+10,M=N*3;
const int INF=0x3f3f3f3f;

int n,k,a[N];

int ch[M][2],tot=1;
void insert(int x){
    int nw=1;
    for(int i=k-1;i>=0;i--){
        int &nxt=ch[nw][x>>i&1];
        if(!nxt) nxt=++tot;
        nw=nxt;
    }
}

vi mx[M],mi[M];
void dfs(int x,int dep=k-1){
    int siz=1<<(dep+1);
    mx[x].resize(siz),mi[x].resize(siz);
    if(dep<0) {mx[x][0]=mi[x][0]=0;return;}
    for(int i=0;i<2;i++)
        if(ch[x][i]) dfs(ch[x][i],dep-1);
    for(int i=0;i<siz;i++){
        int hi=i>>dep&1;
        if(ch[x][hi]) mi[x][i]=mi[ch[x][hi]][i&((1<<dep)-1)];
        else mi[x][i]=mi[ch[x][hi^1]][i&((1<<dep)-1)]|(1<<dep);
        if(ch[x][hi^1]) mx[x][i]=mx[ch[x][hi^1]][i&((1<<dep)-1)]|(1<<dep);
        else mx[x][i]=mx[ch[x][hi]][i&((1<<dep)-1)];
    }
}

int res[K][N];
void solve(int x,int dep=k-1){
    if(dep<0) return;
    if(ch[x][0]&&ch[x][1]){
        for(int i=0;i<(1<<(dep+1));i++){
            int hi=i>>dep&1,ni=i&((1<<dep)-1);
            if(hi) ckmin(res[dep][i],mi[ch[x][0]][ni]+(1<<dep)-mx[ch[x][1]][ni]);
            else ckmin(res[dep][i],mi[ch[x][1]][ni]+(1<<dep)-mx[ch[x][0]][ni]);
        }
    }
    for(int i=0;i<2;i++)
        if(ch[x][i]) solve(ch[x][i],dep-1);
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) 
        a[i]=rdi(),insert(a[i]);
    memset(res,0x3f,sizeof(res));
    dfs(1),solve(1);
    for(int x=0;x<(1<<k);x++){
        int ans=INF;
        for(int i=0;i<k;i++) ans=min(ans,res[i][x&((1<<(i+1))-1)]);
        cout<<ans<<' ';
    }
    return 0;
}