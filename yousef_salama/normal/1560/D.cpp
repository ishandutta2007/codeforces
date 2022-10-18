#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    auto num = [&](long long x){
        string a = "";
        while(x > 0){
            a += (char)('0' + x % 10);
            x /= 10;
        }
        reverse(a.begin(), a.end());
        return a;
    };

    while(t--){
        int n;
        scanf("%d", &n);

        string a = num(n);
        int res = 1 << 30;

        for(int i = 0; i <= 60; i++){
            string b = num(1LL << i);
            
            vector < vector <int> > dp((int)a.size() + 1, vector <int>((int)b.size() + 1));

            for(int i = (int)a.size(); i >= 0; i--)
            for(int j = (int)b.size(); j >= 0; j--){
                if(i == (int)a.size() && j == (int)b.size()){
                    dp[i][j] = 0;
                }else if(i == (int)a.size()){
                    dp[i][j] = (int)b.size() - j;
                }else if(j == (int)b.size()){
                    dp[i][j] = (int)a.size() - i;
                }else{
                    dp[i][j] = 1 + dp[i + 1][j];
                    if(a[i] == b[j])dp[i][j] = min(dp[i][j], dp[i + 1][j + 1]);
                }
            }
            res = min(res, dp[0][0]);
        }
        printf("%d\n", res);
    }
    return 0;
}