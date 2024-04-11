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
#define MOD 1000000007
using namespace std;
int n, m, b;
long long ans = 1;
string s[105];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    bool a[26];
    for(int i = 0; i < m; i++){
        memset(a, 0, sizeof a);
        for(int j = 0; j < n; j++)
            a[s[j][i] - 'A'] = 1;
        b = 0;
        for(int j = 0; j < 26; j++)
            b += a[j];
        ans *= b;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}