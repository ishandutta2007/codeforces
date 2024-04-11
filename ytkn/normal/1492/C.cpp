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

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> dpl(m, INF), dpr(m, INF);
    int cur = 0;
    for(int i = 0; i < m; i++){
        while(s[cur] != t[i]) cur++;
        dpl[i] = cur;
        cur++;
    }
    cur = n-1;
    for(int i = m-1; i >= 0; i--){
        while(s[cur] != t[i]) cur--;
        dpr[i] = cur;
        cur--;
    }
    int ans = 0;
    for(int i = 0; i < m-1; i++){
        chmax(ans, dpr[i+1]-dpl[i]);
    }
    cout << ans << endl;
}