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

const int N=65,MOD=1e9+7;

int n,a[N];
vi e[N],_e[N];

i64 C[N][N];
void init(int n){
    for(int i=0;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) 
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

int id[N];
i64 f[(1<<(N/4))+1][N];
pair<int,i64> solve(const vi &nodes){
    if(nodes.size()==1) {return {0,1};}
    
    for(int i=1;i<=n;i++) id[i]=0;
    
    vi S,T;
    int cnt=0;
    for(auto x:nodes) 
        if(_e[x].empty()) S.pb(x),id[x]=++cnt;
        else T.pb(x);

    static int s[N];
    for(auto x:T){
         s[x]=0;
         for(auto y:_e[x]) 
             if(id[y]) s[x]|=(1<<(id[y]-1));
    }

    f[0][0]=1;
    for(int i=0;i<(1<<cnt);i++){
        for(int j=0;j<=T.size();j++){
            i64 &v=(f[i][j]%=MOD);
            if(!v) continue;
            int c=0;
            for(auto x:T){
                if((s[x]&i)==s[x]) ++c;
                else if((s[x]&i)||!j) (f[s[x]|i][j+1]+=v)%=MOD;
            }
            if(j<c) f[i][j+1]+=v*(c-j)%MOD;
        }
    }
    pair<i64,int> ret={(int)(nodes.size()-S.size()-1),f[(1<<cnt)-1][T.size()]};
    for(int i=0;i<(1<<cnt);i++)
        for(int j=0;j<=T.size();j++) f[i][j]=0;
    return ret;
}

struct Dsu{
    int f[N];
    void init(int n) {iota(f+1,f+n+1,1);}
    int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}
    void merge(int x,int y) {f[find(x)]=find(y);}
}d;

void solve(){
    d.init(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(a[j]%a[i]==0) 
                e[i].pb(j),_e[j].pb(i),d.merge(i,j);
        }
    }
    static vi buf[N];
    for(int i=1;i<=n;i++) buf[d.find(i)].pb(i);
    i64 ans=1;
    for(int i=1,sum=0;i<=n;i++) 
        if(buf[i].size()){
            auto tmp=solve(buf[i]);
            ans=ans*tmp.se%MOD*C[sum+=tmp.fi][tmp.fi]%MOD;
        }
    cout<<ans<<endl;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();init(n);
    for(int i=1;i<=n;i++) a[i]=rdi();
    solve();
    return 0;
}