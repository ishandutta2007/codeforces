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
};

vector<OffsetVec<int>> dp[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] *= 2;
        b[i] *= 2;
    }
    for(int i = 0; i <= 1; i++){
        dp[i] = vector(n+1, OffsetVec<int>(200*n));
        for(int j = 0; j <= n; j++){
            for(int k = -200*n; k <= 200*n; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++){
        int cur = (i+1)%2;
        int pre = i%2;
        for(int j = 0; j <= n; j++){
            for(int k = -200*n; k <= 200*n; k++){
                dp[cur][j][k] = -INF;
            }
        }
        for(int j = 0; j <= i; j++){
            for(int k = -200*n; k <= 200*n; k++){
                if(dp[pre][j][k] == -INF) continue;
                // 
                if(k >= 0){
                    chmax(dp[cur][j][k+b[i]], dp[pre][j][k]);                    
                }else{
                    if(-k >= b[i]/2){
                        int x = b[i]/2;
                        chmax(dp[cur][j][k+x], dp[pre][j][k]+x);
                    }else{
                        int x = -k;
                        chmax(dp[cur][j][b[i]-2*x], dp[pre][j][k]+x);
                    }
                }
                
                // 
                if(k >= 0){
                    // k
                    if(a[i]-b[i] >= k/2){
                        int x = k/2;
                        chmax(dp[cur][j+1][-(a[i]-b[i]-x)], dp[pre][j][k]+b[i]+x);
                    }else{
                        int x = a[i]-b[i];
                        chmax(dp[cur][j+1][k-2*x], dp[pre][j][k]+b[i]+x);
                    }
                }else{
                    chmax(dp[cur][j+1][k-(a[i]-b[i])], dp[pre][j][k]+b[i]);
                }
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        int ans = -INF;
        for(int x = -n*200; x <= n*200; x++) chmax(ans, dp[n%2][k][x]);
        cout << (double)ans/2.0 << ' ';
    }
    cout << endl;
}