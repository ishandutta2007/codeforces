#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define vp vector<P>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> istream& operator>>(istream& is,vector<T>& v) { for(T& t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream& os,const vector<T>& v) { for(T t:v){os<<t<<" ";} os<<"\n"; return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

template<typename T>
class BIT {
    int n;
    vector<T> val;
public:
    BIT(int n):n(n),val(n+1,0) {}
    void add(int i,T x=1) {
        i++;
        while(i <= n) {
            val[i] += x;
            i += i&-i;
        }
    }
    T sum(int i) {
        T ret = 0;
        i++;
        while(i > 0) {
            ret += val[i];
            i -= i&-i;
        }
        return ret;
    }
    // [l,r)
    T sum(int l,int r) { return sum(r-1)-sum(l-1); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,q;
    cin >> n >> q;
    BIT<int> bt(n);
    rep(_,n) {
        int a;
        cin >> a;
        a--;
        bt.add(a);
    }
    while(q--) {
        int k;
        cin >> k;
        if(k > 0) {
            k--;
            bt.add(k);
        } else {
            k = -k;
            int ok = n,ng = -1;
            auto f = [&](int x) {
                return bt.sum(x) >= k;
            };
            while(abs(ok-ng) > 1) {
                int mid = (ng+ok)/2;
                if(f(mid)) ok = mid;
                else ng = mid;
            }
            bt.add(ok,-1);
        }
    }
    if(bt.sum(n-1) == 0) cout << 0 << endl;
    else {
        rep(i,n) if(bt.sum(i) > 0) {
            cout << i+1 << endl;
            break;
        }
    }
}