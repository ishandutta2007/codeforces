#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=2e5+10,INF=0x3f3f3f3f;

int n,a[N][2],f[N][2][2];
int nx[N][2],ans;

template<typename T>
void ckmax(T &a,T b) {if(a<b) a=b;}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=0;i<2;i++){
        static char buf[N];scanf("%s",buf+1);
        for(int j=1;j<=n;j++) a[j][i]=buf[j]-'0';
    }

    nx[n+1][0]=nx[n+1][1]=INF;
    for(int i=n;i>=1;i--){
        nx[i][0]=nx[i+1][0],nx[i][1]=nx[i+1][1];
        if(a[i][0]) nx[i][0]=i;
        if(a[i][1]) nx[i][1]=i;
    }

    memset(f,0xc0,sizeof(f));
    f[1][0][!a[1][1]]=0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=1;k++){
            for(int j=0;j<2;j++){
                if(!a[i][j^1]&&!k) continue;
                if(f[i][j][k]<0) continue;
                int v=f[i][j][k];
                int p1=nx[i+1][j],p2=nx[i+k][j^1];
                if(p1==INF&&p2==INF&&k) ckmax(ans,v);
                else if(p1==p2+1){
                    if(a[p1][j]&&a[p1][j^1]) ckmax(f[p1][j^1][1],v+2),ckmax(f[p1][j][1],v+1);
                    else ckmax(f[p1][j][1],v+1),ckmax(f[p1][j^1][1],v+1);
                }
                else if(!k&&p1>p2+1) ckmax(f[i][j^1][1],v+1);
                else if(p1<INF&&p1==p2) ckmax(f[p1][j][0],v+1),ckmax(f[p1][j][1],v+1);
                else if(p1>p2+1) ckmax(f[p2][j^1][1],v+1),ckmax(f[p2][j][1],v);
                else if(p1<p2+1) ckmax(f[p1][j][1],v+1);
                if(!k) ckmax(f[i+1][j][!a[i+1][j^1]],v+a[i+1][j]);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}