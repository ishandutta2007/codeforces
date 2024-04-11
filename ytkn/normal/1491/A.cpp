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
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a.begin(), a.end(), 0);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x; x--;
            if(a[x] == 0) sum++;
            else sum--;
            a[x] = 1-a[x];
        }else{
            int k; cin >> k;
            if(sum >= k) cout << 1 << endl;
            else cout << 0  << endl;
        }
    }
}