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

const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n,m,t;
    cin >> n >> m >> t;
    vvi v(n,vi(m));
    rep(i,n) {
        string s;
        cin >> s;
        rep(j,m) v[i][j] = s[j]-'0';
    }
    vvi dist(n,vi(m,inf));
    rep(i,n) rep(j,m) rep(k,4) {
        int ni = i+dx[k],nj = j+dy[k];
        if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
        if(v[i][j] == v[ni][nj]) dist[i][j] = 0;
    }
    queue<P> q;
    rep(i,n) rep(j,m) if(dist[i][j] == 0) q.emplace(i,j);
    while(!q.empty()) {
        int i = q.front().first,j = q.front().second;
        q.pop();
        rep(k,4) {
            int ni = i+dx[k],nj = j+dy[k];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
            if(dist[ni][nj] != inf) continue;
            dist[ni][nj] = dist[i][j]+1;
            q.emplace(ni,nj);
        }
    }
    rep(_,t) {
        int i,j;
        ll p;
        cin >> i >> j >> p;
        i--; j--;
        int num = v[i][j];
        if(p < dist[i][j] || dist[i][j] == inf) cout << num << "\n";
        else {
            p -= dist[i][j];
            cout << (p%2 == 0 ? num : 1-num) << "\n";
        }
    }
}