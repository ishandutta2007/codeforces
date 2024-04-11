#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

const int INF = 1e9;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = INF;
    {
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = a[i];
        }
        sort(v.begin(), v.end());
        bool ok = true;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != v[i]){
                cnt++;
            }
        }
        if(cnt == 0) ans = 0;
    }
    for(int i = 0; i < n; i++){
        vector<int> b;
        for(int j = 0; j < n; j++){
            if(j != i) b.push_back(a[j]);
        }
        b.push_back(x);
        sort(b.begin(), b.end());
        bool ok = true;
        int cnt = 0;
        int cur = x;
        for(int j = 0; j < n; j++){
            if(a[j] != b[j]){
                cnt++;
                if(a[j] <= cur) ok = false;
                if(b[j] != cur) ok = false; 
                cur = a[j];
            }
        }
        if(ok) chmin(ans, cnt);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}