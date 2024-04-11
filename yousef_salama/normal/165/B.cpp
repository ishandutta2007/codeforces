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
using namespace std;
int n, k;
long long lines(long long v){
    long long cur = 1, ret = 0;
    while(v / cur != 0){
        ret += v / cur;
        cur *= k;
    }
    return ret;
}
int main(){
    cin >> n >> k;
    long long l = 0, r = 10000000000000LL, v;
    while(l < r){
        v = (l + r) / 2;
        if(lines(v) >= (long long)n)r = v;
        else l = v + 1;
    }
    cout << l << endl;
    return 0;
}