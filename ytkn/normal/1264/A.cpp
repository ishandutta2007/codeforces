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
    int n; cin >> n;
    vector<int> p(n);
    vector<int> v;
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n-1; i++){
        if(p[i] > p[i+1]) v.push_back(i+1);
    }
    v.push_back(n);
    int a = 0, b = 0, c = 0;
    for(int x : v){
        auto pt1 = lower_bound(v.begin(), v.end(), x*2+1);
        if(pt1 == v.end()) continue;
        auto pt2 = lower_bound(v.begin(), v.end(), n/2+1);
        if(pt2 == v.begin()) continue;
        pt2--;
        if((*pt2)-(*pt1) <= x) continue;
        int a_ = x;
        int b_ = (*pt1)-x;
        int c_ = (*pt2)-(*pt1);
        if(a_+b_+c_ > n/2) continue;
        if(a+b+c < a_+b_+c_){
            a = a_;
            b = b_;
            c = c_;
        }
    }
    cout << a << ' ' << b << ' ' << c << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}