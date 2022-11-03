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
typedef int (*func)(int, int);




const int mx = 1e5 + 10;

int xx[] = {0, 0, 1, 1};
int yy[] = {0, 1, 0, 1};

void solve(int tc){
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    vector<pair<pair<int, int>, int>> ans;
    for(auto &i : ss) cin >> i;
    int startX = 0, startY = 0;
    if(n % 2 == 1 && m % 2 == 1){
        startX = 1;
        startY = 1;
        for(int i = 0; i < n - 2; i++){
            if(ss[i][0] == '0') continue;
            ans.push_back({{i, 0}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + i;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        if(ss[n - 2][0] == '1' && ss[n - 1][0] == '1'){
            ans.push_back({{n - 2, 0}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[n - 2][0] == '1'){
            ans.push_back({{n - 2, 0}, 2});
            for(int x = 0; x < 4; x++){
                if(x == 2) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[n - 1][0] == '1'){
            ans.push_back({{n - 2, 0}, 0});
            for(int x = 0; x < 4; x++){
                if(x == 0) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }

        for(int j = 1; j < m - 2; j++){
            if(ss[0][j] == '0') continue;
            ans.push_back({{0, j}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + j;
                ss[X][Y] ^= 1;
            }
        }

        if(ss[0][m - 2] == '1' && ss[0][m - 1] == '1'){
            ans.push_back({{0, m - 2}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[0][m - 2] == '1'){
            ans.push_back({{0, m - 2}, 1});
            for(int x = 0; x < 4; x++){
                if(x == 1) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[0][m - 1] == '1'){
            ans.push_back({{0, m - 2}, 0});
            for(int x = 0; x < 4; x++){
                if(x == 0) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
    }
    else if(m % 2 == 1){
        startY = 1;
        for(int i = 0; i < n - 2; i++){
            if(ss[i][0] == '0') continue;
            ans.push_back({{i, 0}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + i;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        if(ss[n - 2][0] == '1' && ss[n - 1][0] == '1'){
            ans.push_back({{n - 2, 0}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[n - 2][0] == '1'){
            ans.push_back({{n - 2, 0}, 2});
            for(int x = 0; x < 4; x++){
                if(x == 2) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[n - 1][0] == '1'){
            ans.push_back({{n - 2, 0}, 0});
            for(int x = 0; x < 4; x++){
                if(x == 0) continue;
                int X = xx[x] + n - 2;
                int Y = yy[x] + 0;
                ss[X][Y] ^= 1;
            }
        }
    }
    else if(n % 2 == 1){
        startX = 1;
        for(int j = 0; j < m - 2; j++){
            if(ss[0][j] == '0') continue;
            ans.push_back({{0, j}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + j;
                ss[X][Y] ^= 1;
            }
        }

        if(ss[0][m - 2] == '1' && ss[0][m - 1] == '1'){
            ans.push_back({{0, m - 2}, 3});
            for(int x = 0; x < 4; x++){
                if(x == 3) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[0][m - 2] == '1'){
            ans.push_back({{0, m - 2}, 1});
            for(int x = 0; x < 4; x++){
                if(x == 1) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
        else if(ss[0][m - 1] == '1'){
            ans.push_back({{0, m - 2}, 0});
            for(int x = 0; x < 4; x++){
                if(x == 0) continue;
                int X = xx[x] + 0;
                int Y = yy[x] + m - 2;
                ss[X][Y] ^= 1;
            }
        }
    }
    for(int i = startX; i < n; i += 2){
        for(int j = startY; j < m; j += 2){
            vector<int> apa, bukan;
            for(int k = 0; k < 4; k++){
                int X = xx[k] + i;
                int Y = yy[k] + j;
                if(ss[X][Y] == '1') apa.push_back(k);
                else bukan.push_back(k);
            }
            if(sz(apa) == 4){
                for(int k = 0; k < 4; k++)
                    ans.push_back({{i, j}, k});
            }
            else if(sz(apa) == 3 || sz(apa) == 1){
                for(int k : bukan)
                    ans.push_back({{i, j}, k});
            }
            else if(sz(apa) == 2){
                for(int k : apa)
                    ans.push_back({{i, j}, k});
            }
        }
    }
    cout << sz(ans) << '\n';
    for(auto x : ans){
        for(int k = 0; k < 4; k++){
            if(k == x.second) continue;
            int X = x.f.f + xx[k];
            int Y = x.f.s + yy[k];
            cout << X + 1<< ' ' << Y + 1<< ' ';
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}