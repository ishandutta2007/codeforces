#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[3][100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s;
    cin >> s;
    dp[0][0] = 1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        if(s[i] == 'u'){
            dp[0][i+1] = dp[1][i];
            dp[1][i+1] = (dp[0][i]+dp[1][i]+dp[2][i])%MOD;
        }else if(s[i] == 'n'){
            dp[0][i+1] = dp[2][i];
            dp[2][i+1] = (dp[0][i]+dp[1][i]+dp[2][i])%MOD;
        }else{
            dp[0][i+1] = (dp[0][i]+dp[1][i]+dp[2][i])%MOD;
        }
    }
    int N = s.size();
    cout << (dp[0][N]+dp[1][N]+dp[2][N])%MOD << endl;
}