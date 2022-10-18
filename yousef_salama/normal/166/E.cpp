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
int n;
long long a = 0, b = 0, c = 0, d = 1;
int main(){
    cin >> n;
    while(n--){
        int na = (b + c + d) % MOD;
        int nb = (a + c + d) % MOD;
        int nc = (a + b + d) % MOD;
        int nd = (a + b + c) % MOD;
        a = na;
        b = nb;
        c = nc;
        d = nd;
    }
    cout << d << endl;
    return 0;
}