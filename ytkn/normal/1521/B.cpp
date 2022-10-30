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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int m = *min_element(a.begin(), a.end());
    int c = [&](){
        for(int i = 0; i < n; i++){
            if(a[i] == m) return i;
        }
    }();
    cout << n-1 << endl;
    for(int i = 0; i < n; i++){
        if(i == c) continue;
        if((i%2) == (c%2)) cout << c+1 << ' ' << i+1 << ' ' << m << ' ' << m << endl;
        else cout << c+1 << ' ' << i+1 << ' ' << m << ' ' << m+1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}