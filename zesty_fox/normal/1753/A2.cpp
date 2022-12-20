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

const int N=2e5+10;

int a[N],n,sel[N];
void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();
    int sum=accumulate(a+1,a+n+1,0);
    if(sum&1) {puts("-1");return;}
    sum/=2;int cnt=abs(sum);
    for(int i=2;i<=n;){
        if(a[i]*sum<=0) {++i;continue;}
        int j=i;
        while(j<=n&&a[j]*sum>0) ++j;
        for(int k=i;k<j&&cnt;k+=2)
            sel[k]=1,--cnt;
        i=j;
    }
    if(cnt) {puts("-1");return;}
    vector<pii> res;
    for(int i=1;i<=n;){
        int j=i,lst=1;
        while(j<=n&&sel[j]==(lst^1)) lst=sel[j],++j;
        res.pb({i,j-1}),i=j;
    }
    cout<<res.size()<<'\n';
    for(auto cur:res)
        cout<<cur.fi<<' '<<cur.se<<'\n';

    for(int i=1;i<=n;i++) sel[i]=0;
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