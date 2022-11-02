#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+5;
int _,a[maxn],n;

int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        ll ans=0;
        for (int i=2;i<=n;i++) ans+=max(0,a[i-1]-a[i]);
        cout << ans << endl;
    }
    return 0;
}