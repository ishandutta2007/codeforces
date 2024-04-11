//@formatter:off
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = int(s); i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi c(n);
    cin >> c;
    rep(i, n) c[i]--;
    vvi ans;
    vp v;
    int l = c[0], r = c[0] + 1;
    rep2(i, 1, n) {
        if (c[i] == r) r++;
        else {
            v.eb(l, r);
            l = c[i];
            r = c[i] + 1;
        }
    }
    v.eb(l, r);
    auto shuffle = [&](vi &d) {
        int sz = d.size();
        int sum = 0;
        deque<int> q;
        rep(i, sz) {
            for (int j = sum + d[i] - 1; j >= sum; j--) {
                q.push_front(c[j]);
            }
            sum += d[i];
        }
        assert(q.size() == n);
        rep(i, n) {
            c[i] = q.front();
            q.pop_front();
        }
        v.clear();
        l = c[0], r = c[0] + 1;
        rep2(i, 1, n) {
            if (c[i] == r) r++;
            else {
                v.eb(l, r);
                l = c[i];
                r = c[i] + 1;
            }
        }
        v.eb(l, r);
    };
    while (v.size() > 1) {
        int sz = v.size();
        int a = -1, b = -1;
        rep(i, sz) rep(j, sz) {
                if (i <= j) continue;
                if (v[i].second == v[j].first) {
                    a = i, b = j;
                    break;
                }
            }
        assert(a != -1);
        vi temp;
        int sum = 0;
        rep(i, sz) {
            if (i == b) {
                if (sum > 0) temp.pb(sum);
                temp.pb(v[i].second - v[i].first);
                sum = 0;
            } else if (i == a) {
                sum += v[i].second - v[i].first;
                temp.pb(sum);
                sum = 0;
            } else {
                sum += v[i].second - v[i].first;
            }
        }
        if (sum > 0) temp.pb(sum);
        shuffle(temp);
        ans.pb(move(temp));
    }
    cout << ans.size() << '\n';
    for (auto &nv : ans) {
        cout << nv.size() << ' ';
        rep(i, nv.size()) cout << nv[i] << (i == nv.size() - 1 ? '\n' : ' ');
    }
}