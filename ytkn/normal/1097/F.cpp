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
#include <bitset>

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

const int M = 7000;
using bs = bitset<M+1>;

bs divs[M+1];
bs pos[M+1];
bs neg[M+1];

void init(){
    auto et = Eratosthenes(M);
    vector<int> mebius(M+1, 1);
    for(int i = 1; i <= M; i++){
        for(int j = 1; i*j <= M; j++){
            divs[i*j][i] = 1;
        }
    }
    for(int p: et.primes){
        for(int i = 1; i*p <= M; i++){
            if(i%p == 0){
                mebius[i*p] = 0;
            }else{
                mebius[i*p] *= -1;
            }
        }
    }
    for(int x = 1; x <= M; x++){
        for(int i = 1; i*x <= M; i++){
            if(mebius[i] == 1){
                pos[x][i*x] = 1;
            }else if(mebius[i] == -1){
                neg[x][i*x] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int n, q; cin >> n >> q;
    vector<bs> s(n);
    string out;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, v; cin >> x >> v; x--;
            s[x] = divs[v];
        }else if(t == 2){
            int x, y, z; cin >> x >> y >> z; x--; y--; z--;
            s[x] = s[y]^s[z];
        }else if(t == 3){
            int x, y, z; cin >> x >> y >> z; x--; y--; z--;
            s[x] = s[y]&s[z];
        }else{
            int x, v; cin >> x >> v; x--;
            int ans = (pos[v]&s[x]).count() - (neg[v]&s[x]).count();
            ans %= 2;
            ans += 2;
            ans %= 2;
            out += '0'+ans;
        }
    }
    cout << out << endl;
}