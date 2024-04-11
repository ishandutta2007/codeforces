#include <iostream>
#include <vector>

using namespace std;

int a[30], b[30];
bool G[7][7];

void clear(){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            G[i][j] = false;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    if(n <= 6){
        cout << m << endl;
        return 0;
    }
    int N = (1<<m);
    int ans = 0;
    for(int i = 0; i < N; i++){
        clear();
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(i&(1<<j)){
                int s = a[j];
                int t = b[j];
                G[s][t] = true;
                G[t][s] = true;
                cnt++;
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < j; k++){
                for(int l = 0; l < n; l++){
                    if(l != j && l != k){
                        if(G[j][l] && G[k][l])break;
                    }
                    if(l == n-1){
                        ans = max(ans, cnt);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}