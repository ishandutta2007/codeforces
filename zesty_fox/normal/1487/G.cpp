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

const int N=410,CH=26,MOD=998244353;

int n,c[CH];
ll f[2][N][N][3][3],g[N][N],ans;

int main(){
    n=rdi();
    for(int i=0;i<CH;i++) c[i]=rdi();
    
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++) f[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]=(i?1:(CH-2))*(j?1:(CH-2));
    }
    for(int i=3,now=1;i<=n;i++,now^=1){
        memset(f[now],0,sizeof(f[now]));
        for(int j=0;j<=n/2+1;j++){
            for(int k=0;k<=n/2+1;k++){
                for(int x=0;x<=2;x++){
                    for(int y=0;y<=2;y++){
                        for(int z=0;z<=2;z++){
                            if(x&&x==z) continue;
                            (f[now][j+(z==1)][k+(z==2)][y][z]+=(ll)f[now^1][j][k][x][y]*(z?1:(CH-2-(x==z))))%=MOD;
                        }
                    }
                }
            }
        }
    }
    for(int j=n;j>=0;j--){
        for(int k=n;k>=0;k--){
            g[j][k]=((ll)g[j+1][k]+g[j][k+1]+MOD-g[j+1][k+1])%MOD;
            for(int x=0;x<=2;x++){
                for(int y=0;y<=2;y++) (g[j][k]+=f[n&1][j][k][x][y])%=MOD;
            }
        }
    }
    ans=g[0][0];
    for(int i=0;i<CH;i++){
        (ans+=MOD-g[c[i]+1][0])%=MOD;
        for(int j=i+1;j<CH;j++) (ans+=g[c[i]+1][c[j]+1])%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}