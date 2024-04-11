#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi p(n);
        cin >> p;
        rep(i,n) p[i]--;
        vi where(n);
        rep(i,n) where[p[i]] = i;
        bool ok = true;
        vi count(n,1);
        set<int> se;
        multiset<int> cnts;
        rep(i,n) se.insert(i);
        rep(i,n) cnts.insert(1);
        rep(i,n) {
            auto back = cnts.end();
            back--;
            if(count[where[i]] != *back) {
                ok = false;
//                cout << i << endl;
                break;
            }
            se.erase(where[i]);
            cnts.erase(back);
            auto it = se.lower_bound(where[i]);
            if(it == se.end()) continue;
            count[*it] += count[where[i]];
            cnts.insert(count[*it]);
        }
        Yes(ok);
    }
}