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
int main(){
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    long long ans = min(a / (x / __gcd(x, y)), b / (y / __gcd(x, y)));
    cout << (x / __gcd(x, y)) * ans << ' ' << (y / __gcd(x, y)) * ans << endl;
    return 0;
}