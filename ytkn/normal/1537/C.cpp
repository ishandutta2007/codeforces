#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
const ll INF = 2e9;

void solve(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h.begin(), h.end());
    int min_diff = INF;
    for(int i = 0; i < n-1; i++) chmin(min_diff, h[i+1]-h[i]);
    if(h[0] == h[n-1]){
        for(int x : h) cout << x << ' ';
        cout << endl;
        return;
    }

    if(n == 2){
        cout << h[0] << ' ' << h[1] << endl;
        return;
    }
    
    for(int i = 0; i < n-1; i++){
        if(h[i+1]-h[i] == min_diff){
            for(int j = i+1; j < n; j++) cout << h[j] << ' ';
            for(int j = 0; j <= i; j++) cout << h[j] << ' ';
            cout << endl;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}