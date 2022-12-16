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

int n,m,a[N];
void solve(){
    n=rdi(),m=rdi();
    if(n>m) {puts("No");return;}
    if(n&1) a[1]=m-n+1,fill(a+2,a+n+1,1);
    else{
        if(m&1) {puts("No");return;}
        else fill(a+1,a+n-1,1),a[n-1]=a[n]=(m-n+2)/2;
    }
    puts("Yes");
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<'\n';
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