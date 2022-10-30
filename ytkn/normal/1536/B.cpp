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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<string> st;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n && j < i+5; j++){
            string t;
            for(int k = i; k <= j; k++) t += s[k];
            st.insert(t);
        }
    }
    queue<string> que;
    que.push("");
    while(!que.empty()){
        string s = que.front(); que.pop();
        if((!s.empty()) && st.count(s) == 0){
            cout << s << endl;
            return;
        }
        for(int i = 0; i < 26; i++){
            string t = s;
            t += ('a'+i);
            que.push(t);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}