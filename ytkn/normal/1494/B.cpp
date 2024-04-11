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
    int n;
    vector<int> a(4);
    cin >> n;
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 16; i++){
        vector<int> b(4);
        for(int j = 0; j < 4; j++) b[j] = a[j];
        for(int j = 0; j < 4; j++){
            if(i&(1<<j)) {
                b[j]--;
                b[(j+1)%4]--;
            }
        }
        bool ok = true;
        for(int j = 0; j < 4; j++){
            if(b[j] < 0 || b[j] > n-2) ok = false;
        }
        if(ok){
            cout << "YES" << endl;
            return;
        }
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