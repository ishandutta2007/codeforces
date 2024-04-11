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

int n, k;
vector<int> a;
const int INF = 1e9;

bool judge(int x){
    vector<int> b(n);
    vector<int> cumsum(n+1);
    for(int i = 0; i  < n; i++) {
        b[i] = (a[i] < x ? -1 : 1);
        cumsum[i+1] = cumsum[i]+b[i];
    }
    int mx = -INF;
    for(int i = n-1; i >= 0; i--){
        chmax(mx, cumsum[i+1]);
        if(i-k+1 >= 0){
            if(cumsum[i-k+1] < mx) return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n+1;
    while(r-l > 1){
        int c = (l+r)/2;
        if(judge(c)) l = c;
        else r = c;
    }
    cout << l << endl;
}