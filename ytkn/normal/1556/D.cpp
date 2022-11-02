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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

const string OR = "or";
const string AND = "and";

using T = tuple<string, int, int>;

class Simulator{
    public:
    int n, k;
    vector<int> a;
    Simulator(int n, int k): n(n), k(k) {
        a = vector<int>(n);
        for(int i = 0; i < n; i++) a[i] = randint(0, 100);
    };
    int ask(string s, int i, int j){
        if(s == OR) return a[i]|a[j];
        if(s == AND) return a[i]&a[j];
    }
    void verify(int x){
        print_vector(a);
        auto b = a;
        sort(b.begin(), b.end());
        assert(x == b[k-1]);
    }
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
#ifdef DEBUG
    auto sim = Simulator(n, k);
#endif
    map<T, int> memo;
    auto ask = [&](string s, int i, int j){
        if(memo.count(T(s, i, j))){
            return memo[T(s, i, j)];
        }
#ifdef DEBUG
        int ans = sim.ask(s, i, j);
#else
        cout << s << ' ' << i+1 << ' ' << j+1 << endl;
        int ans; cin >> ans;
#endif
        memo[T(s, i, j)] = ans;
        memo[T(s, j, i)] = ans;
        return ans;
    };
    auto verify = [&](int x){
#ifdef DEBUG
        sim.verify(x);
#else
        cout << "finish " << x << endl;
#endif
    };
    vector<int> a_or(n), a_and(n), a_xor(n);
    for(int i = 1; i < n; i++){
        a_or[i] = ask(OR, 0, i);
        a_and[i] = ask(AND, 0, i);
        a_xor[i] = a_or[i]-a_and[i];
    }
    int and12 = ask(AND, 1, 2);
    int and012 = a_and[1]&a_and[2];
    int x = a_or[1]&a_or[2]; // a0|(a1&a2)
    int y = and12-and012; // ((!a0)&a1&a2)
    vector<int> a(n);
    a[0] = x-y;
    for(int i = 1; i < n; i++){
        a[i] = a_xor[i]^a[0];
    }
#ifdef DEBUG
    print_vector(a);
#endif
    sort(a.begin(), a.end());
    verify(a[k-1]);
}