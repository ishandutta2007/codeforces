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

class Eratosthenes{
    public:
    int m;
    vector<bool> is_prime;
    vector<int> primes;
    Eratosthenes(int m_){
        m = m_;
        init();
    }
    private:
    void init(){
        is_prime.assign(m+1, true);
        is_prime[0] = false, is_prime[1] = false;
        for(int i = 2; i <= m; i++){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = 2; i*j <= m; j++) is_prime[i*j] = false;
            }
        }
    }
};

bool used[10000001];
int org[10000001];

void init(){
    for(int i = 1; i <= 10000000; i++) org[i] = i;
    for(int i = 2; i*i <= 10000000; i++){
        for(int j = 1; i*j <= 10000000; j++){
            while(org[i*j]%(i*i) == 0) org[i*j] /= (i*i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        vector<int> buf;
        for(int i = 0; i < n; i++){
            if(used[org[a[i]]]){
                for(int x : buf) used[x] = false;
                ans++;
                buf.clear();
            }
            used[org[a[i]]] = true;
            buf.push_back(org[a[i]]);
        }
        for(int x : buf) used[x] = false;
        cout << ans+1 << endl;
    }
}