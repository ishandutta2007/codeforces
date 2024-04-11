#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
string s;
int N, dp[5000005];
long long ans, Pow[5000005], hash[5000005], rev_hash[5000005];
int main(){
    cin >> s;
    N = s.size();

    Pow[0] = 1;
    for(int i = 1; i < N; i++)
        Pow[i] = Pow[i - 1] * 257;

    for(int i = 0; i < N; i++)
        hash[i] = (i > 0 ? hash[i - 1] : 0) + s[i] * Pow[i];
    for(int i = N - 1; i >= 0; i--)
        rev_hash[i] = (i < N - 1 ? rev_hash[i + 1] : 0) + s[i] * Pow[N - i - 1];

    ans = 0;
    for(int i = 0; i < N; i++){
        if(hash[i] * Pow[N - i - 1] == rev_hash[0] - (i < N - 1 ? rev_hash[i + 1] : 0))
            dp[i] = ((i + 1) / 2 > 0 ? dp[(i + 1) / 2 - 1] : 0) + 1;
        else dp[i] = 0;

        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}