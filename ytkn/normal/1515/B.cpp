#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>
#include <cmath>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    ll n; cin >> n;
    if(n%2 == 1){
        cout << "NO" << endl;
        return;
    }
    ll sq = sqrt(n)+0.1;
    if(sq*sq > n) sq--;
    if(sq*sq == n){
        cout << "YES" << endl;
        return;
    }
    n /= 2;
    sq = sqrt(n)+0.1;
    if(sq*sq > n) sq--;
    if(sq*sq == n){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}