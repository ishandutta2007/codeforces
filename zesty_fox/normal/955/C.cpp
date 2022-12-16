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

const int N=150000;
const ll INF=1e18;
vector<ll> pwr;
ll mysqrt(ll x){
    ll sq=sqrt(x)+1;
    while(sq*sq>x) sq--;
    return sq;
}

ll calc(ll lim){
    return mysqrt(lim)+upper_bound(pwr.begin(),pwr.end(),lim)-pwr.begin()-2;
}

ll L,R;
void solve(){
    L=rdll(),R=rdll();
    printf("%lld\n",calc(R)-calc(L-1));
}

void init(){
    for(ll i=2;i<=1000000;i++){
        ll sq=mysqrt(i);
        if(sq*sq==i) continue;
        
        ll pw=i*i*i;
        for(int j=3;;j+=2){
            pwr.pb(pw);
            if(pw>INF/i/i) break;
            pw*=i,pw*=i;
        }
    }
    sort(pwr.begin(),pwr.end());
    pwr.resize(unique(pwr.begin(),pwr.end())-pwr.begin());
}

int T;
int main(){
    T=rdi();init();
    while(T--) solve();
    return 0;
}