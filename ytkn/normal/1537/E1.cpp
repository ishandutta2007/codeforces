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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<string> v(n);
    for(int i = 1; i <= n; i++){
        string t;
        for(int j = 0; j < i; j++) t += s[j];
        while(v[i-1].size() < k) v[i-1] += t;
        while(v[i-1].size() > k) v[i-1].pop_back();
    }
    sort(v.begin(), v.end());
    cout << v[0] << endl;
}