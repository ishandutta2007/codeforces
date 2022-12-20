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

i64 l,r;

i64 calc(i64 lim){
    i64 ret=0;

    for(int a=0;a<=2;a++){
        i64 l=0,r=2e9;
        while(l<r){
            i64 mid=(l+r+1)/2;
            if(mid*(mid+a)<=lim) l=mid;
            else r=mid-1;
        }
        ret+=l;
    }

    return ret;
}

void solve(){
    l=rdi64(),r=rdi64();
    cout<<calc(r)-calc(l-1)<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--)
        solve();
    return 0;
}