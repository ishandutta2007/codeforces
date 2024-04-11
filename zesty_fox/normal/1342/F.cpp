// LUOGU_RID: 97161697
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

const int N=16,INF=0x3f3f3f3f;

int n,a[N];

int sum[(1<<N)+1];
int f[(1<<N)+1][N][N];
pii g[(1<<N)+1][N][N];
void init(){
    sum[0]=0;
    for(int i=1;i<(1<<n);i++)
        sum[i]=sum[i&(i-1)]+a[__builtin_ctz(i)+1];

    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<=n;j++) for(int k=0;k<=n;k++)
            f[i][j][k]=INF;

}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    
    init();
    f[0][0][0]=0;
    for(int i=0;i<(1<<n);i++){
        int cnt=__builtin_popcount(i);
        for(int j=0;j<=cnt;j++){
            for(int p=j;p<=n;p++){
                if(f[i][j][p]>=INF) continue;
                for(int s=((1<<n)-1)^i,t=s;t;t=(t-1)&s){
                    if(!(t>>p)||sum[t]<=f[i][j][p]) continue;
                    int p1=__builtin_ctz(t>>p)+p+1;
                    if(f[i|t][j+1][p1]>sum[t])
                        f[i|t][j+1][p1]=sum[t],g[i|t][j+1][p1]={t,p};
                }
            }
        }
    }

    int s=(1<<n)-1,cnt,lst;
    for(int j=n;j>=1;j--)
        for(int k=j;k<=n;k++)
            if(f[s][j][k]!=INF) {cnt=j,lst=k;goto ed;}
    ed:
    vector<pii> res;vi p;
    for(int i=1;i<=n;i++) p.pb(i);
    auto op = [&](int i,int j){
        int pi=find(p.begin(),p.end(),i)-p.begin();
        int pj=find(p.begin(),p.end(),j)-p.begin();
        res.pb({pi+1,pj+1}),p.erase(p.begin()+pi);
    };

    while(s){
        int s1=g[s][cnt][lst].fi;
        for(int i=1;i<=n;i++)
            if((s1>>(i-1)&1)&&i!=lst) op(i,lst);
        lst=g[s][cnt][lst].se;
        s^=s1,--cnt;
    }

    cout<<res.size()<<'\n';
    for(auto cur:res) cout<<cur.fi<<' '<<cur.se<<'\n';
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}