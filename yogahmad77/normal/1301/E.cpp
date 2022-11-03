#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<string> ss(n);
    vector<vector<int>> R(n, vector<int>(m, 0));
    vector<vector<int>> G(n, vector<int>(m, 0));
    vector<vector<int>> B(n, vector<int>(m, 0));
    vector<vector<int>> Y(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) cin >> ss[i];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ss[i][j] == 'R')
                R[i][j] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ss[i][j] == 'G')
                G[i][j] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ss[i][j] == 'B')
                B[i][j] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(ss[i][j] == 'Y')
                Y[i][j] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            R[i][j] += R[i][j - 1];
            G[i][j] += G[i][j - 1];
            B[i][j] += B[i][j - 1];
            Y[i][j] += Y[i][j - 1];
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            R[i][j] += R[i - 1][j];
            G[i][j] += G[i - 1][j];
            B[i][j] += B[i - 1][j];
            Y[i][j] += Y[i - 1][j];
        }
    }

    function<int(int, int, int, int, vector<vector<int>>&)> get = [&](int ax, int ay, int bx, int by, vector<vector<int>> &A){
        int sum = A[bx][by];
        if(ax > 0) sum -= A[ax - 1][by];
        if(ay > 0) sum -= A[bx][ay - 1];
        if(ax > 0 && ay > 0) sum += A[ax - 1][ay - 1];
        return sum;
    };

    vector<vector<int>> r(n, vector<int>(m, -1));
    vector<vector<int>> g(n, vector<int>(m, -1));
    vector<vector<int>> b(n, vector<int>(m, -1));
    vector<vector<int>> y(n, vector<int>(m, -1));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; 1; k++){
                int ax = i - k;
                int ay = j - k;
                int bx = i;
                int by = j;
                if(ax < 0 || bx >= n || ay < 0 || by >= m) break;
                int apa = get(ax, ay, bx, by, R);
                if(apa == (bx - ax + 1) * (by - ay + 1)) apa = 1;
                else apa = 0;
                if(!apa) break;
                r[i][j] = k;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; 1; k++){
                int ax = i - k;
                int ay = j;
                int bx = i;
                int by = j + k;
                if(ax < 0 || bx >= n || ay < 0 || by >= m) break;
                int apa = get(ax, ay, bx, by, G);
                if(apa == (bx - ax + 1) * (by - ay + 1)) apa = 1;
                else apa = 0;
                if(!apa) break;
                g[i][j] = k;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; 1; k++){
                int ax = i;
                int ay = j;
                int bx = i + k;
                int by = j + k;
                if(ax < 0 || bx >= n || ay < 0 || by >= m) break;
                int apa = get(ax, ay, bx, by, B);
                if(apa == (bx - ax + 1) * (by - ay + 1)) apa = 1;
                else apa = 0;
                if(!apa) break;
                b[i][j] = k;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; 1; k++){
                int ax = i;
                int ay = j - k;
                int bx = i + k;
                int by = j;
                if(ax < 0 || bx >= n || ay < 0 || by >= m) break;
                int apa = get(ax, ay, bx, by, Y);
                if(apa == (bx - ax + 1) * (by - ay + 1)) apa = 1;
                else apa = 0;
                if(!apa) break;
                y[i][j] = k;
            }
        }
    }

    const int batas = 60;
    vector<vector<int>> pref[batas];
    vector<pair<int, int>> daftar[n + 1];
    for(int i = 0; i < batas; i++){
        pref[i].resize(n, vector<int>(m, 0));
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            int rr = r[i][j];
            int gg = g[i][j + 1];
            int bb = b[i + 1][j + 1];
            int yy = y[i + 1][j];
            for(int k = 0; k <= min(min(rr, gg), min(bb, yy)); k++){
                int ax = i - k;
                int ay = j - k;
                int bx = i + 1 + k;
                int by = j + 1 + k;
                int panjang = (k + 1) * 2;
                if(panjang < batas) pref[panjang][ax][ay] += 1;
                else daftar[panjang].pb({ax, ay});
            }
        }
    }

    for(int k = 0; k < batas; k++){
        for(int i = 0; i < n; i++)
            for(int j = 1; j < m; j++)
                pref[k][i][j] += pref[k][i][j - 1];
        for(int i = 1; i < n; i++)
            for(int j = 0; j < m; j++)
                pref[k][i][j] += pref[k][i - 1][j];
    }

    while(q--){
        int ax, bx, ay, by;
        cin >> ax >> ay >> bx >> by;
        ax -= 1; bx -= 1; ay -= 1; by -= 1;
        int ans = 0;
        for(int panjang = 2; panjang <= n; panjang += 2){
            int AX = ax;
            int AY = ay;
            int BX = bx - panjang + 1;
            int BY = by - panjang + 1;
            if(AX > BX || AY > BY) break;
            if(panjang < batas){
                if(get(AX, AY, BX, BY, pref[panjang]))
                    ans = panjang;
                else break;
                continue;
            }
            for(auto x : daftar[panjang]){
                if(AX <= x.f && x.f <= BX && AY <= x.s && x.s <= BY){
                    ans = panjang;
                    break;
                }
            }
            if(ans != panjang) break;
        }
        cout << ans * ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}