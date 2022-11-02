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

const int INF = 1e5;

bool intersects(int l1, int r1, int l2, int r2){
    if(r2 <= l1 || r1 <= l2) return false;
    return true;
}

int intersection(int l1, int r1, int l2, int r2){
    return max(0, min(r1, r2)-max(l1, l2));  
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m, k; cin >> n >> m >> k;
    vector<int> l(m), r(m);
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
        l[i] += n; r[i] += n;
        l[i]--;
    }
    int ans = 0;
    for(int s = n; s < 2*n; s++){
        int tmp = 0;
        int sum_slope = 0;
        vector<vector<int>>diff(3*n);
        for(int i = 0; i < m; i++){
            if((l[i] <= s) != (r[i] <= s+k)){
                tmp += min(r[i]-l[i], k);
            }else{
                int len = intersection(l[i], r[i], s, s+k);
                int d = k-len;
                tmp += len;
                diff[l[i]-d].push_back(1);
                diff[r[i]-len].push_back(1);
                diff[min(r[i]-k, l[i])].push_back(-1);
                diff[max(l[i], r[i]-k)].push_back(-1);
            }
        }
        // cout << s-n << "==> ";
        for(int t = 0; t+k < 3*n; t++){
            // cout << t-n << ':' << tmp << ' ';
            chmax(ans, tmp);
            for(int x : diff[t]) sum_slope += x;
            tmp += sum_slope;
        }
        // cout << endl;
        chmax(ans, tmp);
    }
    cout << ans << endl;
}