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
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

class Simulator{
    public:
    Simulator(){
        x = randint(0, 1<<14);
        n_asked = 0;
    };
    int ask(vector<int> v){
        assert(v.size() == 100);
        int i = randint(0, 100);
        n_asked++;
        return v[i]^x;
    }
    void verify(int y){
        cout << x << " " << y << endl;
        assert(y == x);
        assert(n_asked == 2);
    }
    private:
    int x;
    int n_asked;
};

// #define DEBUG

#ifdef DEBUG
auto sim = Simulator();
#endif

int ask(vector<int> v){
#ifdef DEBUG
    return sim.ask(v);
#else
    cout << "? ";
    print_vector(v);
    int ans; cin >> ans;
    return ans;
#endif
}

void verify(int x){
#ifdef DEBUG
    return sim.verify(x);
#else
    cout << "! " << x << endl;;
#endif
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int x = 0;
    vector<int> v;
    int mask_left = (1<<7)-1;
    int mask_right = mask_left<<7;
    for(int i = 1; i <= 100; i++){
        v.push_back(i);
    }
    x += ask(v)&mask_right;
    for(int i = 1; i <= 100; i++){
        v[i-1] = (i<<7);
    }
    x += ask(v)&mask_left;
    verify(x);
}