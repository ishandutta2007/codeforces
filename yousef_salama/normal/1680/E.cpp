#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <string> grid(2);
        for(int i = 0; i < 2; i++)
            cin >> grid[i];

        vector <int> gmask(n, 0);
        vector <bool> nonempty(n, false);

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++)
                if(grid[j][i] == '*')gmask[i] |= (1 << j);

            if(gmask[i] != 0)nonempty[i] = true;
            else if(i + 1 < n)nonempty[i] = nonempty[i + 1];
            else nonempty[i] = false;
        }

        vector <int> dp(1 << 2, 1 << 30);
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            vector <int> ndp(1 << 2, 1 << 30);

            for(int j = 0; j < (1 << 2); j++){
                int mask = gmask[i] | j;

                if(mask == 0){
                    ndp[0] = min(ndp[0], dp[j]);
                }else{
                    if(i + 1 < n && nonempty[i + 1]){
                        if(mask == 3){
                            ndp[1] = min(ndp[1], dp[j] + 2);
                            ndp[2] = min(ndp[2], dp[j] + 2);
                        }else ndp[mask] = min(ndp[mask], dp[j] + 1);
                    }else{
                        if(mask == 3)ndp[0] = min(ndp[0], dp[j] + 1);
                        else ndp[0] = min(ndp[0], dp[j]);
                    }
                }
            }

            swap(dp, ndp);
        }

        cout << dp[0] << '\n';
    }

    return 0;
}