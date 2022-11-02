#include <bits/stdc++.h>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;

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

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

__int128 parse(string &s) {
  __int128 ret = 0;
  for (int i = 0; i < s.length(); i++)
    if ('0' <= s[i] && s[i] <= '9')
      ret = 10 * ret + s[i] - '0';
  return ret;
}

istream & operator >> (istream &in,  __int128 &m){
    string s; cin >> s;
    m = parse(s);
    return in;
}

using ll = __int128;

template<typename T>
class ConvexHullTrick{
    public:
    T x;
    ConvexHullTrick<T>(){
        x = -2e9;
    }
    /**
     * x
     */ 
    void next(){
        x++;
        while(dq.size() >= 2 && f(x, dq[0]) >= f(x, dq[1])) dq.pop_front();
    }
    /**
     * x
     */ 
    void proceed(T _x){
        assert(x <= _x);
        x = _x;
        while(dq.size() >= 2 && f(x, dq[0]) >= f(x, dq[1])) dq.pop_front();
    }
    /**
     *  y = p_add*x+q ()
     */ 
    void add_line(T p_add, T q_add){
        if(!dq.empty()) assert(p_add < p[dq.back()]);
        p.push_back(p_add);
        q.push_back(q_add);
        int n_lines = p.size();
        while(dq.size() >= 2 && check(dq[dq.size()-2], dq.back(), n_lines-1)) {
            dq.pop_back();
        }
        dq.push_back(n_lines-1);
    }
    T get_min(){
        return f(x, dq[0]);
    }
    private:
    vector<T> p, q; // p[i]x+q[i]
    deque<int> dq;
    T f(int x, int i){
        return p[i]*x+q[i];
    }
    bool check(int i, int j, int k){
        return (p[j]-p[i])*(q[k]-q[j]) >= (q[j]-q[i])*(p[k]-p[j]);
    };
};



using P = pair<ll, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> x(n), y(n), a(n);
    vector<P> vp(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> a[i];
        vp[i] = P(x[i], i);
    }
    sort(vp.begin(), vp.end());
    vector<ll> dp(n);
    ConvexHullTrick<ll> cht;
    vector<int> indices(n);
    for(int i = 0; i < n; i++) indices[i] = vp[i].second;
    auto add_dp = [&](int idx, ll val){
        dp[idx] = val;
        cht.add_line(-x[idx], -val);
    };
   
    auto calc = [&](int i){
        return x[i]*y[i]-a[i];
    };
    add_dp(indices[0], calc(indices[0]));
    for(int i = 1; i < n; i++){
        int idx = indices[i];
        cht.proceed(-y[idx]);
        ll v = calc(idx) - min((ll)0, cht.get_min());
        add_dp(idx, v);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}