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
int n, a[100005];
long long k;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    k--;
    int idx = k / n;
    int L = idx, R = idx;
    while(L > 0 && a[L] == a[L - 1])L--;
    while(R < n - 1 && a[R] == a[R + 1])R++;
    int m = R - L + 1;
    k -= (long long)L * n;
    cout << a[idx] << ' ' << a[k / m] << endl;
    return 0;
}