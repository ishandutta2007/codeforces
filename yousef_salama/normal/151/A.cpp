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
int n, k, l, c, d, p, nl, np;
int main(){
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int a = (k * l) / nl;
    int b = c * d;
    int c = p / np;
    cout << min(a, min(b, c)) / n << endl;
    return 0;
}