#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5;
const int maxm = 105;
int a[maxn][maxm];

int n, m;
int nm;
pair<int, int> b[maxm];
int ans;
int c[maxn][maxm];

void dfs(int id){
    if(id == nm){
        int sum = 0;
        for(int i = 0;i < n;i++){
            int mx = 0;
            for(int j = 0;j < nm;j++){
                mx = max(mx, c[i][j]);
            }
            sum += mx;
        }
        ans = max(sum, ans);
        return;
    }
    for(int j = 0;j < n;j++){
        for(int k = 0;k < n;k++){
            c[k][id] = a[(k + j) % n][b[id].second];
        }
        dfs(id + 1);
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        nm = min(n, m);
        ans = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 0;i < m;i++){
            int mx = 0;
            for(int j = 0;j < n;j++){
                mx = max(mx, a[j][i]);
            }
            b[i] = make_pair(-mx, i);
        }
        sort(b, b + m);
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}