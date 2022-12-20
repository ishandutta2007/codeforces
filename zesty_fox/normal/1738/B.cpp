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

const int N=1e5+10;

int n,k;
i64 s[N],a[N];
void solve(){
    n=rdi(),k=rdi();
    for(int i=1;i<=k;i++) s[n-k+i]=rdi();
    if(k==1) {puts("Yes");return;}
    for(int i=n-k+2;i<=n;i++) a[i]=s[i]-s[i-1];
    for(int i=n-k+3;i<=n;i++)
        if(a[i-1]>a[i]) {puts("No");return;}
    i64 v=s[n-k+1]<0?(s[n-k+1]/(n-k+1)):(s[n-k+1]+n-k)/(n-k+1);
    if(v>a[n-k+2]) puts("No");
    else puts("Yes");
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}