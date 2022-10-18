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
    long long n, m, s;
    cin >> n >> m >> s;
    n--;m--;
    cout << ((n / s) + 1) * ((m / s) + 1) * ((n % s) + 1) * ((m % s) + 1) << endl;
    return 0;
}