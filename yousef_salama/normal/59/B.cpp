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
int n, sum, Min, a[105];
int main(){
    cin >> n;

    sum = 0;
    Min = -1;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];

        if(a[i] & 1)
            Min = Min == -1 ? a[i] : min(Min, a[i]);
    }
    if(Min == -1)cout << 0 << endl;
    else cout << sum - ((1 - (sum & 1)) * Min) << endl;

    return 0;
}