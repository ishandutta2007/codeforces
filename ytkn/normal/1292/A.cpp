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

bool f[2][100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    int cnt = 0;
    while(q--){
        int r, c; cin >> r >> c; r--;
        if(f[r][c]){
            f[r][c] = false;
            if(f[r^1][c-1]) cnt--;
            if(f[r^1][c]) cnt--;
            if(f[r^1][c+1]) cnt--;
        }else{
            f[r][c] = true;
            if(f[r^1][c-1]) cnt++;
            if(f[r^1][c]) cnt++;
            if(f[r^1][c+1]) cnt++;
        }
        if(cnt > 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}