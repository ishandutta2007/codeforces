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
int t;
long long n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        long long x = 4 * n * (n + 1) / __gcd(4 * n, n + 1);
        cout << x / (n + 1) + 1 << endl;
    }
    return 0;
}