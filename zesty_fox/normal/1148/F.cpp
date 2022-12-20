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

const int N=300010;
int n;
ll hi[N],val[N],mask[N],ans,sum;
inline ll highbit(ll x){
    x|=(x>>1);
    x|=(x>>2);
    x|=(x>>4);
    x|=(x>>8);
    x|=(x>>16);
    x|=(x>>32);
    return (x+1)>>1;
}

void solve(){
    for(int i=0;i<=61;i++){
        ll s=0;
        for(int j=1;j<=n;j++){
            if(!(hi[j]^(1ll<<i))) s+=val[j];
        }
        if(s<=0) continue;
        ans|=(1ll<<i);
        for(int j=1;j<=n;j++){
            if(mask[j]>>i&1) val[j]=-val[j];
        }
    }
}

int main(){
    n=rdi();
    for(int i=1;i<=n;i++) val[i]=rdll(),mask[i]=rdll(),sum+=val[i];
    if(sum<0){
        for(int i=1;i<=n;i++) val[i]=-val[i];
        sum=-sum;
    }
    for(int i=1;i<=n;i++) hi[i]=highbit(mask[i]);
    solve();
    cout<<ans<<endl;
    return 0;
}