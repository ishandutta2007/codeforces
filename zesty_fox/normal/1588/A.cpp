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

const int N=110;

int n,a[N],b[N],cnt[N<<1];

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    for(int i=1;i<=n;i++) b[i]=rdi();
    
    sort(a+1,a+n+1);sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>b[i]) return (void)puts("NO");
        else if(a[i]<b[i]-1) return (void)puts("NO");
    }
    puts("YES");
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}