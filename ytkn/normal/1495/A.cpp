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
#include <cmath>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<double> x, y;
    for(int i = 0; i < 2*n; i++){
        int a, b; cin >> a >> b;
        if(a == 0){
            y.push_back(b);
        }else{
            x.push_back(a);
        }
    }
    vector<double> X(n), Y(n);
    for(int i = 0; i < n; i++){
        X[i] = x[i]*x[i];
        Y[i] = y[i]*y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += sqrt(X[i]+Y[i]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}