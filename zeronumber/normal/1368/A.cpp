#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
int _,ans;
ll a,b,n;
int main(){
    cin >> _;
    while (_--){
        cin >> a >> b >> n; ans=0;
        while (a<=n&&b<=n){
            if (a<b) a+=b; else b+=a;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}