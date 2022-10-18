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
#include <string.h>
#define MOD 1000000007
using namespace std;
int t, d[105][2605];
string s;
int main(){
    d[0][0] = 1;
    for(int i = 1; i < 105; i++)
    for(int rem = 0; rem < 2605; rem++)
        for(int cur = 1; cur <= 26; cur++)
            if(rem - cur >= 0)d[i][rem] = (d[i][rem] + d[i - 1][rem - cur]) % MOD;
    cin >> t;
    while(t--){
        cin >> s;
        int n = s.size(), sum = 0;
        for(int i = 0; i < n; i++)
            sum += s[i] - 'a' + 1;
        cout << (d[n][sum] + MOD - 1) % MOD << endl;
    }
    return 0;
}