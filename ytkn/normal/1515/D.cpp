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
    int n, l, r; cin >> n >> l >> r;
    vector<int> cntl(n);
    vector<int> cntr(n);
    for(int i = 0; i < l; i++) {
        int c; cin >> c; c--;
        cntl[c]++;
    }
    for(int i = 0; i < r; i++) {
        int c; cin >> c; c--;
        cntr[c]++;
    }
    for(int i = 0; i < n; i++){
        int m = min(cntl[i], cntr[i]);
        cntl[i] -= m;
        cntr[i] -= m;
        l -= m;
        r -= m;
    }
    int same = 0;
    if(l > r){
        for(int i = 0; i < n; i++){
            same += (cntl[i]/2)*2;
        }
    }else if(r > l){
        for(int i = 0; i < n; i++){
            same += (cntr[i]/2)*2;
        }
    }
    int d = abs(r-l);
    if(same >= d){
        cout << min(l, r)+d/2 << endl;
    }else{
        cout << min(l, r)+(d-same)+same/2 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}