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
using P = pair<int, int>;

void answer(bool f){
    cout << (f ? "YES" : "NO") << endl;
}

P make_P(int u, int v){
    return P(min(u, v), max(u, v));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    set<P> both, same;
    map<P, char> mp;
    while(m--){
        char c; cin >> c;
        if(c == '+'){
            int u, v; char c; cin >> u >> v >> c;
            if(mp.count(P(v, u))){
                if(mp[P(v, u)] == c) same.insert(make_P(u, v));
                both.insert(make_P(u, v));
            }
            mp[P(u, v)] = c;
        }
        if(c == '-'){
            int u, v; cin >> u >> v;
            mp.erase(P(u, v));
            auto p = make_P(u, v);
            if(same.count(p)) same.erase(p);
            if(both.count(p)) both.erase(p);
        }
        if(c == '?'){
            int k; cin >> k;
            if(k%2 == 0) answer(!same.empty());
            else answer(!both.empty());
        }
    }
}