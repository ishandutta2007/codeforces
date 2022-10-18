#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            assert(i + a[i] < n);
        }

        vector < vector <int> > dp(n, vector <int> (n + 1, n)), suf_min(n, vector <int> (n + 1, n));
        vector <int> row_add(n, 0);

        dp[n - 1][n] = 0;
        suf_min[n - 1] = vector <int>(n + 1, 0);

        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j - i <= a[i]; j++)
                dp[i][j] = min(dp[i][j], suf_min[j][i + a[i] + 1] + row_add[j]);
            for(int j = i + 1; j - i <= a[i]; j++)
                row_add[j]++;

            suf_min[i][n] = dp[i][n];
            for(int j = n - 1; j >= 0; j--)
                suf_min[i][j] = min(suf_min[i][j + 1], dp[i][j]);
            
            /*
            for(int i = 0; i < n; i++){
                for(int j = 0; j <= n; j++)
                    cout << dp[i][j] + row_add[i] << ' ';
                cout << endl;
            }
            cout << "--------------" << endl;
            */
        }
        printf("%d\n", suf_min[0][0]);
    }
    return 0;
}