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

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

string gen_str(int len, int n_chars){
    string ans;
    for(int i = 0; i < len; i++){
        ans += randint(0, n_chars)+'a';
    }
    return ans;
}

class Simulator{
    public:
    int n;
    string s;
    vector<int> asked;
    Simulator(int n): n(n), s(gen_str(n, 26)), asked(vector<int>(2)) {};
    char first_type(int i){
        asked[0]++;
        return s[i];
    };
    int second_type(int l, int r){
        asked[1]++;
        vector<bool> used(26);
        int ans = 0;
        for(int i = l; i < r; i++){
            int idx = s[i]-'a';
            if(!used[idx]){
                ans++;
                used[idx] = true;
            }
        }
        return ans;
    };
    void verify(string t){
        cout << s << ' ' << t << endl;
        assert(s == t);
        print_vector(asked);
        assert(asked[0] <= 26);
        assert(asked[1] <= 6000);
    }
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
#ifdef DEBUG
    auto sim = Simulator(n);
    auto first_type = [&](int i){
        return sim.first_type(i);
    };
    auto second_type = [&](int l, int r){
        return sim.second_type(l, r);
    };
    auto verify = [&](string s){
        return sim.verify(s);
    };
#else
    auto first_type = [&](int i){
        cout << "? 1 " << i+1 << endl;
        char ans; cin >> ans;
        return ans;
    };
    auto second_type = [&](int l, int r){
        cout << "? 2 " << l+1 << ' ' << r << endl;
        int ans; cin >> ans;
        return ans;
    };
    auto verify = [&](string s){
        cout << "! " << s << endl;
    };
#endif
    string ans(n, '.');
    int cnt = 0;
    for(int i = 0; i < n; i++){
        vector<int> last_index(26, -1);
        for(int j = 0; j < i; j++){
            last_index[ans[j]-'a'] = j;
        }
        vector<int> v;
        for(int j = 0; j < 26; j++){
            if(last_index[j] != -1) v.push_back(last_index[j]);
        }
        if(v.empty()){
            char c = first_type(i);
            ans[i] = c;
        }else{
            sort(v.begin(), v.end());
            int m = v.size();
            if(second_type(v[0], i+1) == m+1){ // 
                char c = first_type(i);
                ans[i] = c;
            }else{
                v.push_back(i); m++;
                int l = 0, r = m-1;
                while(r-l > 1){
                    int x = (l+r)/2;
                    if(second_type(v[x], i+1) == m-x-1){
                        l = x;
                    }else{
                        r = x;
                    }
                }
                char c = ans[v[l]];
                ans[i] = c;
            }
        }
    }
    verify(ans);
}