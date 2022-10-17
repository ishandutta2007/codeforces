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
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==v.size()-1?']':','); return os; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << endl; }
void YES(bool b) { cout << (b ? "YES" : "NO") << endl; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

void solve() {
    int n,x,y;
    cin >> n >> x >> y;
    vi b(n);
    cin >> b;
    rep(i,n) b[i]--;
    vector<pair<int,multiset<int>>> v;
    rep(i,n+1) v.eb(i,multiset<int>());
    rep(i,n) v[b[i]].second.insert(i);
    sort(all(v),[](auto a,auto b){ return a.second.size() > b.second.size(); });
    vi ans(n);
    vi can;
    int sz = v[0].second.size();
    int l = 0;
    while(true) {
        while(l < n and v[l+1].second.size() >= sz) l++;
        rrep(i,l+1) can.pb(i);
        if(sz == 1) break;
        sz--;
    }
    auto erase = [&](int i) {
        ans[*v[i].second.begin()] = v[i].first;
        v[i].second.erase(v[i].second.begin());
    };
    rep(i,x) erase(can[i]);
    vi rol(n+1);
    rep(i,n+1) rol[i] = v[i].second.size();
    rep(i,n-y) rol[can[x+i]]--;
    if(v[0].second.size()+rol[0] > n-x) {
        cout << "NO" << '\n';
        return;
    }
    vp ls;
    rep(i,n+1) {
        auto A = v[i];
        if(A.second.empty()) continue;
        auto it = A.second.begin();
        rep(j,A.second.size()) {
            if(j < rol[i]) ls.eb(*it,1);
            else ls.eb(*it,0);
            it++;
        }
    }
    assert(ls.size() == n-x);
    rep(i,n-x) {
        if(ls[i].second) ans[ls[(i+v[0].second.size())%(n-x)].first] = b[ls[i].first];
        else ans[ls[(i+v[0].second.size())%(n-x)].first] = v[n].first;
    }
    cout << "YES" << '\n';
    rep(i,n) cout << ans[i]+1 << (i == n-1 ? '\n' : ' ');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,t) solve();
}