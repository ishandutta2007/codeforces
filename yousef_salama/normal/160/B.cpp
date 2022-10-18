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
int n, a[105], b[105];
string s;
int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        a[i] = s[i] - '0';
    for(int i = n; i < 2 * n; i++)
        b[i - n] = s[i] - '0';
    sort(a, a + n);
    sort(b, b + n);
    bool first = true, second = true;
    for(int i = 0; i < n; i++)
        if(a[i] <= b[i])first = false;
    for(int i = 0; i < n; i++)
        if(b[i] <= a[i])second = false;
    if(first || second)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}