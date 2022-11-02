#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, k;

const int maxn = 505;
int a[maxn][maxn];

int L[maxn * maxn], R[maxn * maxn], U[maxn * maxn], D[maxn * maxn];
int pre[maxn][maxn];
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n * n;i++){
        L[i] = INF; 
        R[i] = -INF;
        U[i] = INF;
        D[i] = -INF;
    }
    int color = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
            L[a[i][j]] = min(L[a[i][j]], i);
            R[a[i][j]] = max(R[a[i][j]], i);
            U[a[i][j]] = min(U[a[i][j]], j);
            D[a[i][j]] = max(D[a[i][j]], j);
        }
    }
    for(int i = 1;i <= n * n;i++){
        if(L[i] != INF){
            color++;
        }
    }
    if(color <= k){
        cout << k - color << endl;
    }else{
        bool flag = false;
        for(int len = 1;len <= n;len++){
            for(int v = 1;v <= n * n;v++){
                if(L[v] == INF)
                    continue;
                int nl = max(1, R[v] - len + 1); 
                int nr = min(n - len + 1, L[v]);
                int nu = max(1, D[v] - len + 1);
                int nd = min(n - len + 1, U[v]); 
                if(nl <= nr and nu <= nd){
                    pre[nl][nu]++;
                    pre[nl][nd + 1]--;
                    pre[nr + 1][nu]--;
                    pre[nr + 1][nd + 1]++;
                }
            } 
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(i == 1 and j == 1){
                        continue;
                    }
                    if(j != 1){
                        pre[i][j] += pre[i][j-1];
                    }
                    if(i != 1){
                        pre[i][j] += pre[i-1][j];
                    }
                    if(i != 1 and j != 1){
                        pre[i][j] -= pre[i-1][j-1];
                    }
                }
            }
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(color - pre[i][j] == k or color - pre[i][j] + 1 == k){
                        flag = true;
                    } 
                    pre[i][j] = 0;
                }
            }
        }
        cout << (flag ? 1 : 2) << endl;
    }
    return 0;
}