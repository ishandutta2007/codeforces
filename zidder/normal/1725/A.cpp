#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

//-----------------------------------------------
#define LOG
#ifdef LOG
    #define db(x)     cerr << #x << ": " << x << endl;
    #define dbA(x, s) cerr << #x << ": "; for (int i = 0; i < s; i++) cerr << x[i] << " "; cerr << endl;
#else
    #define db(x)
    #define dbA(x, s)
#endif
//-----------------------------------------------
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//-----------------------------------------------
template<class K, class V> ostream& operator << (ostream& out, const pair<K, V>& obj) { out << "{ " << obj.first << ", " << obj.second << " }"; return out; }
template<class T> ostream& operator << (ostream& out, const vector<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const deque<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const unordered_set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const ordered_set<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class T> ostream& operator << (ostream& out, const ordered_multiset<T>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class K, class V> ostream& operator << (ostream& out, const map<K, V>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
template<class K, class V> ostream& operator << (ostream& out, const unordered_map<K, V>& obj) { out << "{ "; for (auto& elem : obj) out << elem << " "; out << "}"; return out; }
//-----------------------------------------------
#define all(x)  x.begin(), x.end()
#define sz(x)   (int)x.size()
#define sq(x)   (x) * (x)
#define fr      first
#define sc      second
#define newline puts("")
//-----------------------------------------------
using ll = long long;
using ld = long double;
//-----------------------------------------------
const int N   = 500 * 1000 + 5;
const ll mod  = 1000000007;
const ll mod3 = 998244353;
const ll INFL = 2000000000 * 1ll * 1000000000 + 500000;
const ll INF  = 1000000000;
const ld pi   = acosl(-1.0);
//-----------------------------------------------

int n, m;

void input() {
    scanf("%d%d", &n, &m);
}

void solve(int test_id) {
    if (m == 1) {
        cout << n - 1 << endl;
    } else {
        cout << n * 1ll * (m - 1) << endl;
    }
}

int main() {
    int testcases = 1;
    // scanf("%d", &testcases);
    for(int test_id = 1; test_id <= testcases; test_id++) {
        input();
        solve(test_id);
    }
    return 0;
}