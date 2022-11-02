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
/**
 * verified: https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=6665000#1 
 */
int edit_distance(string s, string t){
    int n = s.size(), m = t.size();
    auto dp = vector<vector<int>>(n+1, vector<int>(m+1, n+m));
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x = s[i] == t[j] ? 0 : 1;
            dp[i+1][j+1] = min({dp[i][j]+x, dp[i+1][j]+1, dp[i][j+1]+1});
        }
    }
    return dp[n][m];
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
    int n, n_asked;
    string s;
    Simulator(): n(300), n_asked(0), s(gen_str(n, 2)) { }
    int ask(string t){
        n_asked++;
        assert(n_asked <= n+2);
        return edit_distance(s, t);
    }
};

// #define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
#ifdef DEBUG
    auto sim = Simulator();
    auto ask = [&](string t){
        return sim.ask(t);
    };
#else
    auto ask = [&](string t){
        cout << t << endl;
        int dist; cin >> dist;
        return dist;
    };
#endif
    string as = string(300, 'a');
    string bs = string(300, 'b');
    int a_edited = ask(as);
    if(a_edited == 0) return 0;
    int b_edited = ask(bs);
    if(b_edited == 0) return 0;
    int ma = 300-a_edited;
    int mb = 300-b_edited;
    if(ma == 0){
        assert(ask(string(mb, 'b')) == 0);
        return 0;
    }
    if(mb == 0){
        assert(ask(string(ma, 'a')) == 0);
        return 0;
    }
    int len = ma+mb;
    vector<int> cnt(ma+1);
    auto make_query = [&](){
        string ans;
        for(int i = 0; i <= ma; i++){
            for(int j = 0; j < cnt[i]; j++) ans += 'b';
            if(i != ma){
                ans +='a';                
            }
        }
        return ans;
    };
    for(int i = 0; i < ma; i++){
        while(true){
            cnt[i]++;
            string t = make_query();
            int dist = ask(t);
            if(dist == 0) return 0;
            if(t.size()+dist > len){
                cnt[i]--;
                break;
            }
        }
    }
    int rem = mb-accumulate(cnt.begin(), cnt.end(), 0);
    cnt[ma] = rem;
    int d = ask(make_query());
    assert(d == 0);
}