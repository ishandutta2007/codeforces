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

void solve(int n){
    vector<int> p(n);
    for(int i = 0; i < n; i++) p[i] = i;
    vector<int> a, b;
    ll sum = 0;
    auto exec = [&](ll i, ll j){
        swap(p[i], p[j]);
        a.push_back(i);
        b.push_back(j);
        sum += (j-i)*(j-i);
    };
    exec(0, n-1);
    for(int i = 1; i < n-1; i++){
        if(i > n-1-i){
            exec(i, 0);
        }else{
            exec(i, n-1);
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << sum << endl;
    for(int i = 0; i < n; i++) cout << p[i]+1 << ' ';
    cout << endl;
    cout << n-1 << endl;
    for(int i = 0; i < n-1; i++) cout << a[i]+1 << ' ' << b[i]+1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        solve(n);
    }
}