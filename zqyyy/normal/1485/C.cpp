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

int x,y;
ll ans;
void solve(){
    x=rdi(),y=rdi();
    int d=2;ans=0;
    for(;d<=y+1&&(d-1)<=x/(d-1);d++) ans+=(d-1)*(d-1)/d;
    for(int l=d,r=y+1;l<=min(y+1,x);l=r+1){
        r=min(min(y+1,x),x/(x/l));
        ans+=(r-l+1)*(x/l);
    }
    printf("%lld\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}