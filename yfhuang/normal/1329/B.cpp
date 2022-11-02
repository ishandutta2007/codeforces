#include <bits/stdc++.h>
using namespace std;

int t;
typedef long long ll;

ll d, m;

int main(){
    cin >> t;
    while(t--){
        cin >> d >> m;
        ll ans = 1;
        for(int i = 0;(1LL << i) <= d;i++){
            ll num = min(d - (1LL << i) + 1, (1LL << i));
            ans = ans * (num + 1) % m;
        }
        ans = (ans + m - 1) % m;
        cout << ans << endl;
    }
    return 0;
}