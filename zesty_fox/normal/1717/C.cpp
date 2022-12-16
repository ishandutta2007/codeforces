#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=2e5+10;

int n,a[N],b[N];
void solve(){
    n=rdi();
    for(int i=0;i<n;i++) a[i]=rdi();
    for(int i=0;i<n;i++) b[i]=rdi();
    for(int i=0;i<n;i++){
        if(a[i]>b[i]) {puts("NO");return;}
        else if(a[i]==b[i]) continue;
        else if(b[i]>b[(i+1)%n]+1) {puts("NO");return;}
    }
    puts("YES");
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