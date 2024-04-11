#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <string> g(n);
        int mn_x = 10, mn_y = 10;
        for(int i = 0; i < n; i++){
            cin >> g[i];

            for(int j = 0; j < m; j++)if(g[i][j] == 'R'){
                mn_x = min(mn_x, i);
                mn_y = min(mn_y, j);
            }
        }

        bool found = false;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)if(g[i][j] == 'R'){
            if(i <= mn_x && j <= mn_y){
                found = true;
            }
        }

        if(found)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}