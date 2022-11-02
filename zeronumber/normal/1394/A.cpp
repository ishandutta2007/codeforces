#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+5;
ll a[maxn],b[maxn],p,q,n,m,d,ans;

int main(){
    cin >> n >> d >> m;
    for (int i=1;i<=n;i++){
        ll x; cin >> x;
        if (x>m) a[++p]=x; else b[++q]=x;
    }
    sort(a+1,a+p+1); sort(b+1,b+q+1);
    for (int i=1;i<=p;i++) a[i]+=a[i-1];
    for (int i=1;i<=q;i++) b[i]+=b[i-1];
    ans=b[q];
    for (int i=1;i<=p;i++){
        ll w=d*(i-1);
        if (w+i>n) break;
        ans=max(ans,a[p]-a[p-i]+b[q]-b[max(0ll,w-(p-i))]);
    }
    cout << ans << endl;
    return 0;
}