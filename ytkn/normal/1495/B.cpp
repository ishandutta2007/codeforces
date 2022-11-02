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
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<int> l(n), r(n);
    l[0] = 0;
    int max_d = 0;
    for(int i = 1; i < n; i++){
        if(p[i-1] < p[i]) l[i] = l[i-1]+1;
        else l[i] = 0;
        chmax(max_d, l[i]);
    }
    r[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        if(p[i+1] < p[i]) r[i] = r[i+1]+1;
        else r[i] = 0;
        chmax(max_d, r[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == max_d) cnt++;
        if(r[i] == max_d) cnt++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(l[i] == max_d && r[i] == max_d) {
            if(cnt == 2 && max_d%2 == 0) ans++;
        }
    }
    // for(int i = 0; i < n; i++) cout << l[i] << ' ' << r[i] << endl;
    cout << ans << endl;
}