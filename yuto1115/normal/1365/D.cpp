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

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

void solve() {
    int n,m;
    cin >> n >> m;
    vs s(n);
    cin >> s;
    rep(i,n) rep(j,m) if(s[i][j] == 'B') {
        rep(k,4) {
            int ni = i+dx[k],nj = j+dy[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(s[ni][nj] == '#') continue;
            if(s[ni][nj] == '.') s[ni][nj] = '#';
            if(s[ni][nj] == 'G') {
                cout << "No\n";
                return;
            }
        }
    }
    vvi v(n,vi(m,0));
    queue<P> q;
    if(s[n-1][m-1] == '.') {
        v[n-1][m-1] = 1;
        q.emplace(n-1,m-1);
    }
    while(q.size()) {
        int i = q.front().first,j = q.front().second;
        q.pop();
        rep(k,4) {
            int ni = i+dx[k],nj = j+dy[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(s[ni][nj] == '#') continue;
            if(v[ni][nj]) continue;
            v[ni][nj] = 1;
            q.emplace(ni,nj);
        }
    }
    rep(i,n) rep(j,m) if(s[i][j] == 'G') {
        if(!v[i][j]) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i,t) solve();
}