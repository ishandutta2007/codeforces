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

bool judge(string t){
    int cur = 0;
    for(char c : t){
        if(c == '(') cur++;
        else cur--;
        if(cur < 0) return false;
    }
    return cur == 0;
}

void solve(){
    string s; cin >> s;
    for(int i = 0; i < 8; i++){
        string t;
        for(char c : s){
            int j = c-'A';
            if(i&(1<<j)) t += '(';
            else t += ')';
        }
        if(judge(t)){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}