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

int inv[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

pair<int, int> parse(){
    string s; cin >> s;
    int hh = (s[0]-'0')*10+(s[1]-'0');
    int mm = (s[3]-'0')*10+(s[4]-'0');
    return make_pair(hh, mm);
}

pair<int, int> inverse(int hh, int mm){
    if(inv[hh%10] == -1 || inv[hh/10] == -1 || inv[mm%10] == -1 || inv[mm/10] == -1) return make_pair(-1, -1);
    return make_pair(inv[mm%10]*10+inv[mm/10], inv[hh%10]*10+inv[hh/10]);
}

void solve(){
    int h, m; cin >> h >> m;
    auto [hh, mm] = parse();
    auto ok = [&](int hh, int mm){
        auto [a, b] = inverse(hh, mm);
        return a >= 0 && a < h && b >= 0 && b < m;
    };
    while(true){
        if(ok(hh, mm)){
            string sh = to_string(hh);
            string sm = to_string(mm);
            if(sh.size() == 1) sh = "0"+sh;
            if(sm.size() == 1) sm = "0"+sm;
            cout << sh << ':' << sm << endl;
            return;
        }
        mm++;
        if(mm == m){
            mm = 0;
            hh++;
            if(hh == h) hh = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        solve();
    }
}