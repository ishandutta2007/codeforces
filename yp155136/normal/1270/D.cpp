#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
/* ordered_set notes:
    .order_of_key(k): Number of items strictly smaller than k
    .find_by_order(k): k-th element in a set
*/
#ifdef cychien
#define debug(...) do {\
  fprintf(stderr, "%s - %d : (%s) = ", __PRETTY_FUNCTION__, __LINE__, #__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0) 
template<typename I> void _DO(I&&x) {cerr << x << '\n';}
template<typename I, typename ...T> void _DO(I&&x,T&&...tail) {cerr << x << ", "; _DO(tail...);}
#define IOS
#define DE(v) {cerr << "[";\
               for(auto it = (v).begin(); it != (v).end(); it++){\
                 it++;\
                 int flag = (it == (v).end());\
                 it--;\
                 cerr << *it;\
                 if (!flag) cerr << ", ";\
             } cerr << "]\n";}
#else
#define debug(...)
#define DE(v)  
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#endif
#define W(v) {for(auto it = (v).begin(); it != (v).end(); it++){\
                 it++;\
                 int flag = (it == (v).end());\
                 it--;\
                 cout << *it << " \n"[flag];\
             }}
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR1(i, n) for(int i = 1; i <= n; i++)
#define pb emplace_back
#define mp make_pair
#define rsz resize
#define X first
#define Y second
#define SZ(x) (ll)x.size()
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
template<class T> bool chmin(T &a, T b) { return b < a && (a = b, true); }
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const int NF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;
const ld PI = 3.14159265358979323846264338327950288;
set<int> qr;
pii ask(){
    cout << "?";
    for (auto& x : qr){
        cout << ' ' << x;
    }
    cout << endl;
    int pos, val; cin >> pos >> val;
    return mp(pos, val);
}
set<int> yp_qr;
pii yp_ask() {
  cout << "?";
    for (auto& x : yp_qr){
        cout << ' ' << x;
    }
    cout << endl;
    int pos, val; cin >> pos >> val;
    return mp(pos, val);
}
int main() {
    IOS;
    int n, k; cin >> n >> k;
    vector<pii> mid;
    FOR1 (i, k - 1) qr.insert(i);
    for (int i = k; i <= n; i++){
        qr.insert(i);
        auto [pos, val] = ask();
        mid.pb(val, pos);
        qr.erase(pos);
    }
    SORT(mid);
    pii f = mid[0];
    pii goal = mid.back();
    qr.insert(f.Y); qr.insert(goal.Y);
    int ans = 1;
    yp_qr = qr;
    for (auto idx : qr){
        if (idx != f.Y && idx != goal.Y){
            yp_qr.erase(idx);
            if (yp_ask().X == goal.Y){
                ++ans;
            }
            yp_qr.insert(idx);
        }
    }
    cout << "! " << ans << endl;
    return 0;
}