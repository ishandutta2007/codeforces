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

int f[100][100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int m = n*n;
    vector<int> cnt(4);
    auto put = [&](int x, int parity){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(parity >= 0 && (j+k)%2 != parity) continue;
                if(f[j][k] == 0){
                    cout << x << ' ' << j+1 << ' ' << k+1 << endl;
                    f[j][k] = x;
                    return;
                }
            }
        }
    };
    for(int i = 0; i < m; i++){
        int a; cin >> a;
        if(cnt[1] == (m+1)/2){
            int x = (a == 2 ? 3 : 2);
            put(x, -1);
            continue;
        }
        if(cnt[2] == (m)/2){
            int x = (a == 1 ? 3 : 1);
            put(x, -1);
            continue;
        }
        if(a == 1){
            put(2, 1);
            cnt[2]++;
        }else{
            put(1, 0);
            cnt[1]++;
        }
    }
}