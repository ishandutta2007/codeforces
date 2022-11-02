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
    ll n; cin >> n;
    ll p = 1;
    for(ll i = 1; i <= n; i++){
        if(gcd(i, n) == 1){
            p = (p*i)%n;
        }
    }
    vector<int> ans;
    ans.push_back(1);
    for(ll i = 2; i <= n; i++){
        if(gcd(i, n) == 1 && p != i){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(ll x : ans) cout << x << ' ';
    cout << endl;
}