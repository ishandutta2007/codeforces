#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector <int> v, w;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);

        if(a == 0){
            w.push_back(i);
        }else{
            v.push_back(i);
        }
    }

    vector < vector <int> > dp(v.size() + 1, vector <int> (w.size() + 1));
    
    for(int i = 0; i <= (int)v.size(); i++)
    for(int j = 0; j <= (int)w.size(); j++){
        if(i == 0){
            dp[i][j] = 0;
        }else if(j == 0){
            dp[i][j] = 1 << 29;
        }else{
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(v[i - 1] - w[j - 1]));
        }
    }

    printf("%d\n", dp[v.size()][w.size()]);

    return 0;
}