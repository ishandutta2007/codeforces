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

bool ok(vector<int> a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(a[i] <= a[j] && a[j] <= a[k]) return false;
                if(a[i] >= a[j] && a[j] >= a[k]) return false;
            }
        }
    }
    // for(int x: a) cout << x << ' ';
    // cout << endl;
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = i; j < i+4 && j < n; j++){
            v.push_back(p[j]);
            if(ok(v)) ans++;
            else break;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}