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

const int N=200010;

int n,a[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    sort(a+1,a+n+1);
    bool flg=1;
    for(int i=1;i<=n;i++) flg&=(a[i]!=1);
    if(flg) return (void)puts("Yes");
    if(!a[1]) return (void)puts("No");
    int gc=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=1) continue;
        if(a[i]==a[i-1]+1) {return (void)puts("No");}
    }
    puts("Yes");
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}