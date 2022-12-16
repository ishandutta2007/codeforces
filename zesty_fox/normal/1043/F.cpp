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
#define mp make_pair
#define pb push_back

const int N=300010,MOD=1e9+7;
int n,a[N],mx[N],mn[N],gc[N],f[N],maxn;

inline ll qpow(ll x,ll y=MOD-2){
	ll res=1;
	while(y){
		if(y&1) (res*=x)%=MOD;
		(x*=x)%=MOD;y>>=1;
	}
	return res;
}

ll fac[N],faci[N];
void init_fac(int lim){
	fac[0]=1;
	for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i%MOD;
	faci[lim]=qpow(fac[lim]);
	for(int i=lim-1;i>=0;i--) faci[i]=faci[i+1]*(i+1)%MOD;
}

inline ll C(int x,int y){
	if(x<0||y<0||x<y) return 0;
	return fac[x]*faci[y]%MOD*faci[x-y]%MOD;
}

int main(){
    n=rdi();init_fac(N-10);
    for(int i=1;i<=n;i++) a[i]=rdi(),maxn=max(maxn,a[i]);
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i]/j;j++){
            if(a[i]%j) continue;
            mx[j]++;
            if(j*j!=a[i]) mx[a[i]/j]++;
        }
    }
    
    for(int res=1;res<=7;res++){
        for(int i=1;i<=maxn;i++) f[i]=0;
        for(int i=maxn;i>=1;i--){
            f[i]=C(mx[i],res);
            for(int j=2;j<=maxn/i;j++){
                f[i]=(f[i]-f[j*i]+MOD)%MOD;
            }
        }
        for(int i=1;i<=maxn;i++){
            if(f[i]>0){
                if(!mn[i]) mn[i]=res;
                else mn[i]=min(mn[i],res);
            }
        }
    }
    printf("%d\n",mn[1]?mn[1]:-1);
    return 0;
}