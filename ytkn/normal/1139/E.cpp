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


const int INF = 100000000;

template<typename Cap>
struct edge {
    int to;
    Cap cap;
    int rev;
};

template<typename Cap>
class FordFolkerson{
    public:
        FordFolkerson(int n){
            N = n;
            G = vector<vector<edge<Cap>>>(n, vector<edge<Cap>>());
            used = vector<bool>(n, false);
        }

        void add_edge(int from, int to, Cap cap){
            G[from].push_back((edge<Cap>{to, cap, (int)G[to].size()}));
            G[to].push_back((edge<Cap>{from, 0, (int)G[from].size()-1}));
        }

        Cap max_flow(int s, int t){
            Cap flow = 0;
            while(true){
                clear_used();
                Cap f = dfs(s, t, INF);
                if(f == 0){
                    break;
                }
                flow += f;
            }
            return flow;
        }

    private:
        vector<vector<edge<Cap>>> G;
        vector<bool> used;
        int N;
        void clear_used(){
            for(int i = 0; i < N; i++) used[i] = false;
        }

        Cap dfs(int v, int t, Cap f){
            if(v == t) return f;
            used[v] = true;
            for(int i = 0; i < G[v].size(); i++){
                edge<Cap> &e = G[v][i];
                if(!used[e.to] && e.cap > 0){
                    int d = dfs(e.to, t, min(f, e.cap));
                    if(d > 0){
                        e.cap -= d;
                        G[e.to][e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> p(n), c(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    int p_max = *max_element(p.begin(), p.end());
    int d; cin >> d;
    vector<int> k(d);
    vector<bool> erased(n);
    for(int i = 0; i < d; i++) {
        cin >> k[i];
        k[i]--;
        erased[k[i]] = true;
    }
    auto club_index = [&](int i){
        return i+1;
    };
    auto p_index = [&](int x){
        return x+1+m;
    };
    auto mf = FordFolkerson<int>(m+p_max+3);
    int s = 0, t = m+p_max+2;
    for(int i = 0; i < m; i++){
        mf.add_edge(s, club_index(i), 1);
    }
    auto add_student = [&](int i){
        mf.add_edge(club_index(c[i]), p_index(p[i]), 1);
    };
    auto add_p = [&](int x){
        mf.add_edge(p_index(x), t, 1);
    };
    for(int i = 0; i < n; i++){
        if(!erased[i]) {
            add_student(i);
        }
    }
    vector<int> ans(d);
    int flow = 0;
    int cur_p = 0;
    for(int j = d-1; j >= 0; j--){
        while(cur_p <= p_max && cur_p == flow){
            add_p(cur_p);
            cur_p++;
            int f = mf.max_flow(s, t);
            if(f == 0) break;
            flow += f;
        }
        ans[j] = flow;
        add_student(k[j]);
        flow += mf.max_flow(s, t);
    }
    print_vector(ans, '\n');
}