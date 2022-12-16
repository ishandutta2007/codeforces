#include <bits/stdc++.h>

using namespace std;

using ll=long long;
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=510,MOD=998244353;

int n,lim;

ll C[N][N];
void init(){
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
}

inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

ll f[N][N];
void solve(){
    for(int i=2;i<=n;i++){
        for(int j=1;j<=lim;j++){
            for(int l=1,r;;l=r+1){
                r=(l+i-2)/(i-1)*(i-1);
                (f[i][j]+=qpow(min(r,j)-l+1,i))%=MOD;
                if(r>j) break;
                for(int k=1,pw=r-l+1;k<=i-2;k++,pw=(ll)pw*(r-l+1)%MOD){
                    (f[i][j]+=f[i-k][j-r]*pw%MOD*C[i][k])%=MOD;
                }
            }
        }
    }
}

int main(){
    n=rdi(),lim=rdi();
    init();solve();
    cout<<f[n][lim]<<endl;
    return 0;
}