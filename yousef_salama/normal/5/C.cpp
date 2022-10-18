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
//
string s;
stack <int> S;
int M[1000005], dp[1000005];
int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        M[i] = -1;
        if(s[i] == '(')S.push(i);
        else{
            if(!S.empty()){
                M[S.top()] = i;
                S.pop();
            }
        }
    }
    for(int i = s.size() - 1; i >= 0; i--)
        if(M[i] != -1)dp[i] = dp[i + 1] + dp[M[i] + 1] + 2;
    int best = *max_element(dp, dp + s.size() + 1);
    if(best == 0)cout << 0 << ' ' << 1 << endl;
    else{
        int cnt = count(dp, dp + s.size() + 1, best);
        cout << best << ' ' << cnt << endl;
    }
    return 0;
}