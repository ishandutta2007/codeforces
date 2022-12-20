#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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

template<typename T>
inline void ckmin(T &a,T b) {if(a>b) a=b;}

const int N=5010,K=9,INF=0x3f3f3f3f;

int n,k,p[N],pos[N];
int f[N][(1<<K)+1];
short sum[N][N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i++) p[i]=rdi(),pos[p[i]]=i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) sum[i][pos[j]]++;
        for(int j=n;j>=1;j--) sum[i][j]+=sum[i][j+1];
    }

    memset(f,0x3f,sizeof(f));
    f[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(1<<(k+1));j++){
            int v=f[i][j];
            if(v>=INF) continue;
            if(j&1) ckmin(f[i+1][j>>1],v);
            else{
                for(int cur=0;cur<=k;cur++){
                    if(i+cur>n||j>>cur&1) continue;
                    int cnt=sum[i-1][pos[i+cur]];
                    for(int p=0;p<=k;p++)
                        if((j>>p&1)&&pos[i+p]>pos[i+cur]) cnt++;
                    ckmin(f[i][j|(1<<cur)],v+cnt);
                }
            }
        }
    }

    cout<<f[n+1][0]<<'\n';
    return 0;
}