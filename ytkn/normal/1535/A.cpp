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

bool solve(vector<int> s){
    if(s[0] < s[1]) swap(s[0], s[1]);
    if(s[2] < s[3]) swap(s[2], s[3]);
    if(s[0] < s[3] || s[2] < s[1]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        vector<int> s(4);
        for(int i = 0; i < 4; i++) cin >> s[i];
        if(solve(s)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}