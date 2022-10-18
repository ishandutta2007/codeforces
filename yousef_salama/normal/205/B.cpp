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
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    long long ans = 0;
    for(int i = n - 1; i > 0; i--)
        ans += max(0, a[i - 1] - a[i]);
    cout << ans << endl;
    return 0;
}