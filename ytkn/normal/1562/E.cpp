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
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

class SuffixArray{
    public:
        vector<int> rank;
        vector<int> sa;
        vector<int> lcp;
        string S;
        int n;
        SuffixArray(string _S){
            S = _S;
            n = _S.size();
            rank = vector<int>(n+1);
        }
        void construct_sa(){
            sa = vector<int>(n+1);
            vector<int> buf(n+1);
            for(int i = 0; i <= n; i++){
                sa[i] = i;
                rank[i] = i < n ? S[i] : -1;
            }

            for(int k = 1; k <= n; k *= 2){
                sort(sa.begin(), sa.end(), [&, k](int i, int j){
                    return compare_sa(i, j, k);
                });

                buf[sa[0]] = 0;
                for(int i = 1; i <= n; i++){
                    buf[sa[i]] = buf[sa[i-1]] + (compare_sa(sa[i-1], sa[i], k) ? 1 : 0);
                }
                for(int i = 0; i <= n; i++) rank[i] = buf[i];
            }
        }

        // sa should be initlally constructed
        void construct_lcp(){
            lcp = vector<int>(n+1);

            int h = 0;
            lcp[0] = 0;
            for(int i = 0; i < n; i++){
                int j = sa[rank[i]-1];

                if(h > 0) h--;
                while(j+h < n && i+h < n){
                    if(S[i+h] != S[j+h]) break;
                    h++;
                }
                lcp[rank[i]-1] = h;
            }
        }
        
        void construct_both(){
            construct_sa();
            construct_lcp();
        }

        // return: t <= s[i..] ?
        bool compare(string t, int i){
            int m = t.size();
            for(int j = 0; j < m && i+j < S.size(); j++){
                if(t[j] != S[i+j]) return t[j] < S[i+j]; 
            }
            return i+m <= n;
        }

        /**
         * TODO: verify
         */ 
        int lower_bound(string t){
            if(compare(t, sa[0])) return 0;
            if(!compare(t, sa[n])) return n+1;
            int l = 0, r = n-1;
            while(r-l > 1){
                int c = (l+r)/2;
                if(compare(t, sa[c])) r = c;
                else l = c;
            }
            return r;
        }
    private:
        // (rank[i], rank[i+k]) vs (rank[j], rank[j+k])
        bool compare_sa(int i, int j, int k){
            if(rank[i] != rank[j]) return rank[i] < rank[j];
            else{
                int ri = i+k <= n ? rank[i+k] : -1;
                int rj = j+k <= n ? rank[j+k] : -1;
                return ri < rj;
            }
        }
};

struct edge{
    int to, index_from;
};

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    auto sa = SuffixArray(s);
    sa.construct_both();
    vector<vector<edge>> g(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++) dp[i] = n-i;
    for(int i = 1; i < (int)sa.sa.size(); i++){
        int lcp = sa.lcp[i];
        for(int j = i+1; j < (int)sa.sa.size(); j++){
            if(sa.sa[i] < sa.sa[j]) g[sa.sa[i]].push_back(edge{sa.sa[j], lcp});
            chmin(lcp, sa.lcp[j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(edge e: g[i]){
            int max_len = n-e.to;
            int tmp = dp[i]+max_len-e.index_from;
            chmax(dp[e.to], tmp);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}