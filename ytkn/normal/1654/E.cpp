#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
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

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

template <typename T>
class OffsetVec{
    public:
	int n;
    vector<T> v;
	T& operator[](int x) {
        return v[x+n];
	}
    void print(){
        for(int i = -n; i <= n; i++) cout << v[i+n] << ' ';
        cout << endl;
    }
    OffsetVec(int _n){
        n = _n;
        v = vector<T>(2*n+1);
    }
    OffsetVec(int _n, T x){
        n = _n;
        v = vector<T>(2*n+1, x);
    }
};

const int N = 100000;

OffsetVec<int> cnt(N);

int sub_solve(vector<int> a){
    int n = a.size();
    int sq = sqrt(N)+10;
    int mx = 0;
    for(int i = 0; i < n; i++){
        cnt[a[i]]++;
        chmax(mx, cnt[a[i]]);
    }
    for(int i = 0; i < n; i++){
        cnt[a[i]]--;
        chmax(mx, cnt[a[i]]);
    }
    for(int d = 1; d <= sq; d++){
        vector<vector<int>> indices(d);
        for(int i = 0; i < n; i++){
            int r = a[i]%d;
            r += d;
            r %= d;
            indices[r].push_back(i);
        }
        for(int r = 0; r < d; r++){
            for(int i: indices[r]){
                int x = ((a[i]-r)-i*d)/d;
                cnt[x]++;
                chmax(mx, cnt[x]);
            }
            for(int i: indices[r]){
                int x = ((a[i]-r)-i*d)/d;
                cnt[x]--;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= i+sq && j < n; j++){
            int d = a[j]-a[i];
            if(d%(j-i) != 0) continue;
            int x = d/(j-i);
            cnt[x]++;
            chmax(mx, cnt[x]+1);
        }

        for(int j = i+1; j <= i+sq && j < n; j++){
            int d = a[j]-a[i];
            if(d%(j-i) != 0) continue;
            int x = d/(j-i);
            cnt[x]--;
        }
    }
    return n-mx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = sub_solve(a);
    reverse(a.begin(), a.end());
    chmin(ans, sub_solve(a));
    cout << ans << endl;
}