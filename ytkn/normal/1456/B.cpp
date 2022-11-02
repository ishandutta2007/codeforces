#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n >= 100){
        cout << 1 << endl;
        return 0;
    }
    int ans = INF;
    for(int i = 1; i < n-1; i++){
        int xo_l = 0;
        for(int l = 1; i-l >= 0; l++){
            xo_l ^= a[i-l];
            int xo_r = 0;
            for(int r = 1; i+r-1 < n; r++){
                xo_r ^= a[i+r-1];
                if(xo_l > xo_r){
                    chmin(ans, l+r-2);
                }
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    
}