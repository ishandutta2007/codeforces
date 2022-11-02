#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;

typedef long double D;
const D EPS = 1e-10;

D ans;
D c, m, p, v;

void dfs(D c, D m, bool C, bool M, D prob, int step){
    if(!C and !M){
        ans += prob * step;
        return; 
    }
    ans += step * prob * (1 - c - m);
    if(C){
        if(c > v + EPS){
            dfs(c - v, m + (M ? v / 2 : 0), C, M, prob * c, step + 1);
        }else{
            dfs(0, m + (M ? c / 2 : 0), 0, M, prob * c, step + 1);
        }
    }
    if(M){
        if(m > v + EPS){
            dfs(c + (C ? v / 2 : 0), m - v, C, M, prob * m, step + 1);
        }
        else{
            dfs(c + (C ? m / 2 : 0), 0, C, 0, prob * m, step + 1);
        }
    }
} 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        ans = 0;
        cin >> c >> m >> p >> v;
        dfs(c, m, 1, 1, 1, 1);
        cout << fixed << setprecision(10) << ans << endl; 
    }
    return 0;
}