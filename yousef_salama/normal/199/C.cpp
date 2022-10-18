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
long long k, b, n, t;
int main(){
    cin >> k >> b >> n >> t;
    long long cur = 1;
    int cnt = 0;
    while(cur < t){
        cnt++;
        cur = k * cur + b;
    }
    if(cur == t)cout << max(n - cnt, 0LL) << endl;
    else cout << max(n - cnt + 1, 0LL) << endl;
    return 0;
}