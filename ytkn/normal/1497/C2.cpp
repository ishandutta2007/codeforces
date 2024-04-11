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

void solve3(int n){
    if(n%2 == 0){
        if(n%4 == 0){
            cout << n/2 << ' ' << n/4 << ' ' << n/4<< endl;
        }else{
            cout << 2 << ' ' << (n-2)/2 << ' ' << (n-2)/2 << endl;
        }
    }else{
        cout << 1 << ' ' << (n-1)/2 << ' ' << (n-1)/2 << endl;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < k-3; i++) cout << 1 << ' ';
    solve3(n-k+3);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}