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
using P = pair<int, int>;

ll tri(ll x){
    return (x*(x+1))/2;
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> d(n+1), k(n+1);
    for(int i = 0; i < n; i++){
        d[i+1] = d[i];
        k[i+1] = k[i];
        if(s[i] == 'D') d[i+1]++;
        if(s[i] == 'K') k[i+1]++;
    }

    map<P, int> cnt;
    for(int i = 0; i < n; i++){
        int g = gcd(d[i+1], k[i+1]);
        P p = P(d[i+1]/g, k[i+1]/g);
        if(cnt.count(p)) cnt[p]++;
        else cnt[p] = 1;
        cout << cnt[p] << ' ';
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