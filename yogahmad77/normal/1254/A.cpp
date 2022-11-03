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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

char ke(int x){
    if(x < 26) return 'a' + x;
    x -= 26;
    if(x < 26) return 'A' + x;
    x -= 26;
    return '0' + x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> ss(n);
        for(int i = 0; i < n; i++) cin >> ss[i];
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cnt += (ss[i][j] == 'R' ? 1 : 0);
        int kecil = cnt / k;
        int sisa = cnt % k;
        vector<int> brp(k, 0);
        for(int i = 0; i < k; i++) brp[i] = kecil;
        for(int i = 0; i < sisa; i++) brp[i] += 1;
        int now = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                for(int j = 0; j < m; j++){
                    if(brp[now] == 0 && ss[i][j] == 'R') now += 1;
                    if(ss[i][j] == 'R') brp[now] -= 1;
                    ans[i][j] = now;
                }
            }
            else{
                for(int j = m - 1; j >= 0; j--){
                    if(brp[now] == 0 && ss[i][j] == 'R') now += 1;
                    if(ss[i][j] == 'R') brp[now] -= 1;
                    ans[i][j] = now;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) cout << ke(ans[i][j]);
            cout << '\n';
        }
    }
}