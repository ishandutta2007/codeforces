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

class Judge{
    public:
    int n;
    int x;
    int init;
    Judge(int n): n(n) {
        x = rand()%n;
        init = x;
    };
    int ask(int q){
        if(x == q) return 1;
        cerr << "asked:" << q << ' ' << x <<  "->" << (x^q) << endl;
        x ^= q;
        return 0;
    }
};

// #define DEBUG

void solve(){
    int n, k; cin >> n >> k;
    int x = 0;
    #ifdef DEBUG
    auto jd = Judge(n);
    #endif
    auto ask = [&](int q){
        #ifdef DEBUG
        return jd.ask(q);
        #else
        cout << q << endl;
        int r; cin >> r;
        return r;
        #endif
    };
    for(int i = 0; i < n; i++){
        int r = ask(i^x);
        if(r == 1) return;
        x ^= (i^x);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}