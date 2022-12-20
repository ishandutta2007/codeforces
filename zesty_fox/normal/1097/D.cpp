#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int MOD=1e9+7,N=110,M=10010;
ll n,k;
vector<pair<ll,int> > pr;
void fact(ll x){
    ll lim=sqrt(x+2);
    for(ll i=2;i<=lim;i++){
        if(x%i==0){
            pr.pb(mp(i,0));
            while(x%i==0) prev(pr.end())->se++,x/=i;
            lim=sqrt(x+2);
        }
    }
    if(x>1) pr.pb(mp(x,1));
}

ll inv[N];
inline ll qpow(ll x,ll y=MOD-2){
    ll res=1;
    while(y){
        if(y&1) (res*=x)%=MOD;
        (x*=x)%=MOD;y>>=1;
    }
    return res;
}

void init_inv(){
    for(int i=1;i<N;i++) inv[i]=qpow(i);
}

ll pw[N];
void init_pw(ll p){
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*p%MOD;
}

ll f[M][N],ans=1;
int main(){
    n=rdll(),k=rdi();
    fact(n);init_inv();
    for(auto tmp:pr){
        ll p=tmp.fi,zs=tmp.se,sum=0;
        init_pw(p);
        for(int i=0;i<=zs;i++) f[0][i]=(i==zs);
        for(int i=1;i<=k;i++){
            for(int j=0;j<=zs;j++){
                f[i][j]=0;
                for(int k=j;k<=zs;k++){
                    (f[i][j]+=f[i-1][k]*inv[k+1])%=MOD;
                }
            }
        }
        for(int i=0;i<=zs;i++){
            (sum+=f[k][i]*pw[i])%=MOD;
        }
        (ans*=sum)%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}