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
    int n, x; cin >> n >> x;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    int sum = accumulate(w.begin(), w.end(), 0);
    if(sum == x){
        cout  << "NO" << endl;
        return;
    }
    int tmp = 0;
    cout << "YES" << endl;
    int i = 0;
    while(i < n){
        if(tmp+w[i] == x){
            cout << w[i+1] << ' ' << w[i] << ' ';
            tmp += w[i]+w[i+1];
            i += 2;
        }else{
            cout << w[i] << ' ';
            tmp += w[i];
            i++;
        }
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();

}