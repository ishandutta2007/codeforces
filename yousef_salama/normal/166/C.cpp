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
int n, x, a[100005];
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    bool found = false;
    for(int i = 0; i < n; i++)
        if(a[i] == x)found = true;
    int ans = 0;
    if(!found){
        a[n++] = x;
        ans++;
    }
    sort(a, a + n);
    while(a[(n + 1) / 2 - 1] != x){
        a[n++] = x;
        ans++;
        sort(a, a + n);
    }
    cout << ans << endl;
    return 0;
}