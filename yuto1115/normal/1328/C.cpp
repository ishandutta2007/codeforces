#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;
const ll linf = 1001001001001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(_,t) {
        int n;
        string x;
        cin >> n >> x;
        vector<int> a(n),b(n);
        bool same = true;
        rep(i,n) {
            int now = x[i]-'0';
            if(now == 0) {
                a[i] = 0;
                b[i] = 0;
            } else if(now == 1) {
                if(same) {
                    a[i] = 1;
                    b[i] = 0;
                    same = false;
                } else {
                    a[i] = 0;
                    b[i] = 1;
                }
            } else {
                if(same) {
                    a[i] = 1;
                    b[i] = 1;
                } else {
                    a[i] = 0;
                    b[i] = 2;
                }
            }
        }
        rep(i,n) cout << a[i];
        cout << endl;
        rep(i,n) cout << b[i];
        cout << endl;
    }
}