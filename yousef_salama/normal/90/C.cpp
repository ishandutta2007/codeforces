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
int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n % 2 == 0)cout << 0 << endl;
    else if(n == 1)cout << min(a[0], m * k) << endl;
    else{
        long long maxN = INT_MAX;
        for(int i = 0; i < n; i += 2)
            maxN = min(maxN, a[i]);
        maxN = min(maxN, (m / (n / 2 + 1) * k));
        cout << maxN << endl;
    }
    return 0;
}