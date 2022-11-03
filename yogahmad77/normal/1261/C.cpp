#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e6 + 10;

int n, m;
string ss[mx];

int get(int ax, int bx, int ay, int by, vector<vector<int>> &pref){
    ax = max(ax, 0);
    bx = min(bx, n - 1);
    ay = max(ay, 0);
    by = min(by, m - 1);
    if(ax == 0 && ay == 0) return pref[bx][by];
    if(ax == 0) return pref[bx][by] - pref[bx][ay - 1];
    if(ay == 0) return pref[bx][by] - pref[ax - 1][by];
    return pref[bx][by] - pref[bx][ay - 1] - pref[ax - 1][by] + pref[ax - 1][ay - 1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    n += 2;
    m += 2;
    for(int i = 0; i < m; i++){
        ss[0] += '.';
        ss[n - 1] += '.';
    }
    for(int i = 1; i < n - 1; i++){
        cin >> ss[i];
        ss[i] = '.' + ss[i];
        ss[i] += '.';
    }
    // for(int i = 0; i < n; i++) {debug(ss[i]); };
    int lo = 0, hi = min(n, m), mid, ans = 0;
    vector<vector<int>> pref(n, vector<int> (m, 0)), sim;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) pref[i][j] = (ss[i][j] == 'X' ? 1 : 0);
            else if(i == 0) pref[i][j] = pref[i][j - 1] + (ss[i][j] == 'X' ? 1 : 0);
            else if(j == 0) pref[i][j] = pref[i - 1][j] + (ss[i][j] == 'X' ? 1 : 0);
            else pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (ss[i][j] == 'X' ? 1 : 0);
        }
    }
    while(lo <= hi){
        mid = (lo + hi) >> 1;
        vector<vector<int>> ya(n, vector<int> (m, 1)), pref2(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ss[i][j] == '.'){
                    ya[i][j] = 0;
                    continue;
                }
                int ax = i - mid;
                int bx = i + mid;
                int ay = j - mid;
                int by = j + mid;
                if(1LL * (bx - ax + 1) * (by - ay + 1) == get(ax, bx, ay, by, pref)) continue;
                ya[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ya[i][j]){
                    // debug(mid, i, j, ya[i][j]);
                }
                if(i == 0 && j == 0) pref2[i][j] = ya[i][j];
                else if(i == 0) pref2[i][j] = pref2[i][j - 1] + ya[i][j];
                else if(j == 0) pref2[i][j] = pref2[i - 1][j] + ya[i][j];
                else pref2[i][j] = pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1] + ya[i][j];
            }
        }
        int yo = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(ss[i][j] == '.'){
                    continue;
                }
                int ax = i - mid;
                int bx = i + mid;
                int ay = j - mid;
                int by = j + mid;
                if(get(ax, bx, ay, by, pref2) == 0){
                    yo = 0;
                    // debug(mid, i, j);
                    break;
                }
            }
            if(!yo) break;
        }
        if(yo){
            lo = mid + 1;
            ans = mid;
            sim = ya;
        }
        else hi = mid - 1;
    }
    cout << ans << endl;
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(sim[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
}