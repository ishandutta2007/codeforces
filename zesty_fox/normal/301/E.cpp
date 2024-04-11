#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD=1e9+7,N=105;

int n,m,k;
int f[2][N][N][N],C[N][N];
ll ans;

void init(){
    for(int i=0;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=min(C[i-1][j-1]+C[i-1][j],N);
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi(),k=rdi();
    init();f[0][0][1][1]=1;
    for(int i=0,now=0;i<=m;i++,now^=1){
        for(int j=0;j<=n+1;j++){
            for(int gp=0;gp<=n;gp++){
                for(int v=1;v<=k;v++){
                    auto &val=f[now][j][gp][v];
                    if(!val) continue;
                    if(!gp) ans+=(ll)val*(m-i+1)%MOD;
                    else{
                        for(int c=(!i?max(gp,2):gp);c<=n+1-j;c++){
                            int nxtv=v*C[c-1][gp-1];
                            if(nxtv>k) continue;
                            (f[now^1][j+c][c-gp][nxtv]+=val)%=MOD;
                        }
                    }
                    val=0;
                }
            }
        }
    }
    ans%=MOD;
    cout<<ans<<endl;
    return 0;
}