#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll n, p;
    cin >> n >> p;
    // int ans = 100;
    for(int i = 1; i < 50; i++){
        ll m = n-p*i;
        if(m <= 0) break;
        int cnt = 0;
        for(int i = 0; i <= 40; i++){
            ll k = ((ll)1)<<i;
            if(k&m) cnt++;
        }
        // cout << i << ' '  << cnt << ' ' << m <<  endl;
        if(cnt <= i && i <= m) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}