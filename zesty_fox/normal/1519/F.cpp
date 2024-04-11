#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=7,INF=0x3f3f3f3f;
constexpr int pw5[N]={1,5,25,125,625,3125,15625};

int n,m,a[N],b[N],c[N][N];
int f[N][pw5[N-1]];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=m;i++) b[i]=rdi();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) c[i][j]=rdi();
    
    memset(f,0x3f,sizeof(f));

    int stat=0;
    for(int i=1;i<=m;i++) stat+=pw5[i-1]*b[i];
    f[0][stat]=0;

    for(int i=1;i<=n;i++){
        static int sum[(1<<N)+1];
        for(int j=0;j<(1<<m);j++){
            sum[j]=0;
            for(int k=1;k<=m;k++) sum[j]+=(j>>(k-1)&1)*c[i][k];
        }

        for(int j=0;j<pw5[m];j++){
            if(f[i-1][j]>=INF) continue;
            for(int k=0;k<(1<<m);k++){
                function<void(int,int,int,int)> dfs = [&](int x,int stat,int s,int rest){
                    if(x>m){
                        if(!rest) f[i][stat]=min(f[i][stat],f[i-1][j]+sum[k]);
                        return;
                    }
                    int cap=stat/pw5[x-1]%5;
                    if(!(s>>(x-1)&1)) cap=0;
                    for(int i=0;i<=min(cap,rest);i++)
                        dfs(x+1,stat-pw5[x-1]*i,s,rest-i);
                };
                dfs(1,j,k,a[i]);
            }
        }
    }
    int ans=*min_element(f[n],f[n]+pw5[m]);
    cout<<(ans>=INF?-1:ans)<<endl;
    return 0;
}