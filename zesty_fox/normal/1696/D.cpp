#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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

const int N=250010;

int n,a[N],to[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    static int st1[N],tp1,st2[N],tp2;
    to[n]=n,tp1=tp2=0;
    st1[tp1=1]=n,st2[tp2=1]=n;
    for(int i=n-1;i>=1;i--){
        to[i]=i+1;
        while(tp1&&a[i]<a[st1[tp1]]) --tp1;
        while(tp2&&a[i]>a[st2[tp2]]) --tp2;
        if(a[i]<a[i+1]){
            int lim=(tp1?st1[tp1]-1:n);
            to[i]=*lower_bound(st2+1,st2+tp2+1,lim,greater<int>());
        }
        else{
            int lim=(tp2?st2[tp2]-1:n);
            to[i]=*lower_bound(st1+1,st1+tp1+1,lim,greater<int>());
        }
        st1[++tp1]=st2[++tp2]=i;
    }
    int x=1,ans=0;
    while(x<n) x=to[x],++ans;
    cout<<ans<<'\n';
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