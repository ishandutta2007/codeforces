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

const int N=100010;

int n;
ll a[N];

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    if(n<=2) return (void)puts("0");
    ll gc=a[2]-a[1],res=0;
    for(int i=3;i<=n;i++){
        int now=a[i]-a[i-1];
        if(now!=gc){
            res=abs(now-gc);
            break;
        }
    }
    if(!res) return (void)puts("0");
    for(int i=1;i<=n;i++){
        if(a[i]>=res||(i>1&&a[i]!=(a[i-1]+gc+res)%res)) return (void)puts("-1");
    }
    printf("%lld %lld\n",res,(gc+res)%res);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}