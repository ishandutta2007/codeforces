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
using P = pair<int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    vector<P> p;
    for(int i = 0; i < k; i++){
        int nx = (i+1)%k;
        int pre = (i+k-1)%k;
        p.push_back(P(i, i));
        for(int j = 0; j < i; j++){
            if(j != i && j != nx && j != pre){
                p.push_back(P(i, j));
                p.push_back(P(j, i));
            }
        }
        p.push_back(P(i, nx));
    }
    if(k > 2){
        for(int i = 0; ;){
            int pre = (i+k-1)%k;
            p.push_back(P(i, pre));
            i = pre;
            if(i == 0) break;
        }
    }
    int cnt = 0;
    int m = p.size();
    while(cnt < n){
        cout << (char)('a'+p[cnt%m].first);
        cnt++;
    }
    cout << endl;
}