#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        string s;
        cin >> n >> s;

        vector <int> dp(n);
        map < pair <int, int>, int> mp;

        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            a += (s[i] == 'D');
            b += (s[i] == 'K');
            int g = __gcd(a, b);
        
            pair <int, int> cur = make_pair(a / g, b / g);
            if(mp.count(cur)){
                dp[i] = mp[cur] + 1;
            }else{
                dp[i] = 1;
            }
            mp[cur] = dp[i];
        }

        for(int i = 0; i < n; i++){
            if(i > 0)printf(" ");
            printf("%d", dp[i]);
        }
        printf("\n");
    }
    return 0;
}