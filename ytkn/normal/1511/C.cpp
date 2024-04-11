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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    auto exec = [&](int idx){
        int x = a[idx];
        for(int i = idx; i > 0; i--){
            a[i] = a[i-1];
        }
        a[0] = x;
    };
    auto find = [&](int b){
        for(int i = 0; i < n; i++){
            if(a[i] == b) return i;
        }
    };
    while(q--){
        int t; cin >> t; t--;
        int x = find(t);
        cout << x+1 << ' ';
        exec(x);
    }
    cout << endl;
}