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

int calc(int a1, int a2){
    if(a1 == a2) return a1;
    return min(a1, a2)+(max(a2, a1)-min(a2, a1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--){
        int n, k1, k2; cin >> n >> k1 >> k2;
        int w, b; cin >> w >> b;
        int l1 = n-k1, l2 = n-k2;
        if(w <= calc(k1, k2) && b <= calc(l1, l2)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}