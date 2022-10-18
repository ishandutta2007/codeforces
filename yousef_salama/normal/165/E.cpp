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
int n, a[1000005], d[5 * 1000005];
int main(){
    cin >> n;
    memset(d, -1, sizeof d);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        d[a[i]] = a[i];
    }
    for(int msk = 1; msk < 5 * 1000005; msk++)
    for(int i = 0; i <= 22; i++)
        if((msk & (1 << i)) && d[msk ^ (1 << i)] != -1)
            d[msk] = d[msk ^ (1 << i)];
    for(int i = 0; i < n; i++){
        int v = ((1 << 22) - 1) & ~a[i];
        cout << d[v] << ' ';
    }
    cout << endl;
    return 0;
}