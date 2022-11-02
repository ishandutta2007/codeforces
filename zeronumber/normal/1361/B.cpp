#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1234567+10;
const int M=1000000007;
int _,n,p,a[maxn];
void sub(ll &x,ll y){x-=y;if(x<0)x+=M;}
ll pow_(ll x,ll y){
    ll ret=1;
    while (y){
        if (y&1) ret=ret*x%M;
        x=x*x%M; y>>=1;
    }
    return ret;
}
void solve(){
    scanf("%d%d",&n,&p);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    if (p==1){
        printf("%d\n",n&1);
        return;
    }
    sort(a+1,a+n+1);
    ll dif=0; int pos=a[n];
    for (int i=n;i;i--){
        if (!dif) ++dif,pos=a[i];
        else {
            while (pos>a[i]){
                pos--;
                dif=dif*p;
                if (dif>i){
                    ll ans=dif%M*pow_(p,pos)%M;
                    for (int j=1;j<=i;j++) sub(ans,pow_(p,a[j]));
                    printf("%lld\n",ans);
                    return;
                }
            }
            dif--;
        }
    }
    ll ans=dif%M*pow_(p,pos)%M;
    printf("%lld\n",ans);
}
int main(){
    cin >> _;
    while (_--){
        solve();
    }
}