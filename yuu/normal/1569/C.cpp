#include <bits/stdc++.h>
using namespace std;
const int64_t base=998244353;
int n;
int a[200001];
int64_t f[200001];
int64_t r[200001];
int64_t power(int64_t a, int64_t x){
    if(x==0) return 1;
    int64_t t=power(a, x/2);
    (t*=t)%=base;
    if(x%2) (t*=a)%=base;
    return t;
}
int64_t C(int n, int k){
    return ((f[n]*r[k])%base*r[n-k])%base;
}
void solve(){
//p1 p2 p3 p4 pk p5 p6 ... pn p1 p2 p3 p4 pk p5 p6 ... pn p1 p2 p3 p4 p5 pk ..pn
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    if(a[n]-a[n-1]>1){
        cout<<"0\n";
        return;
    }
    if(a[n]==a[n-1]){
        int64_t ans=1;
        for(int i=2; i<=n; i++) (ans*=i)%=base;
        cout<<ans<<'\n';
        return;
    }
    //a[n]==a[n-1] + 1
    //a[n] has to go before at least one of the a[n-1];
    int cnt=0;
    for(int i=1; i<=n; i++) cnt+=(a[i]==a[n-1]);
    int64_t ans=1;
    (ans*=C(n, cnt+1))%=base;
    (ans*=f[n-cnt-1])%=base;
    (ans*=f[cnt])%=base;
    (ans*=cnt)%=base;
    cout<<ans<<'\n';
}

int main(){
    f[0]=1;
    for(int i=1; i<=200000; i++) (f[i]=f[i-1]*i)%=base;
    r[200000]=power(f[200000], base-2);
    for(int i=200000; i>=1; i--) (r[i-1]=r[i]*i)%=base;
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}