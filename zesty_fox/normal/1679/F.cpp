// LUOGU_RID: 95300722
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

const int D=10,MOD=998244353;

int n,m;
int e[D][D];
i64 f[2][(1<<D)+1];

int to[(1<<D)+1][D];
void init(){
    for(int i=0;i<(1<<D);i++){
        for(int cur=0;cur<D;cur++){
            if(i>>cur&1) continue;
            for(int nxt=0;nxt<D;nxt++){
                if(e[cur][nxt]&&((i>>nxt&1)||cur>nxt))
                    to[i][cur]|=(1<<nxt);
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        e[x][y]=e[y][x]=1;
    } 
    init();
    f[1][0]=1;i64 ans=0;
    for(int i=1,nw=1;i<=n;i++,nw^=1){
        for(int j=0;j<(1<<D);j++){
            i64 &val=f[nw][j];
            if(!val) continue;
            val%=MOD;
            if(i==n){
                ans+=(D-__builtin_popcount(j))*val;
                continue;
            }
            for(int cur=0;cur<D;cur++){
                if(j>>cur&1) continue;
                f[nw^1][to[j][cur]]+=val;
            }
            val=0;
        }
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}