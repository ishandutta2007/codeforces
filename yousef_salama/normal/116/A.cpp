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
//    freopen("a.in", "r", stdin);
    int n, a, b;
    cin >> n;
    int cur = 0, maxN = 0;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cur -= a;
        cur += b;
        maxN = max(cur, maxN);
    }
    cout << maxN << endl;
    return 0;
}