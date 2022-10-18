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
int n, t;
pair <int, int> p[1005];
int main(){
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p, p + n);

    int ans = 2;
    for(int i = 0; i < n - 1; i++){
        int dist = (p[i + 1].first - p[i].first) * 2 - p[i].second - p[i + 1].second;
        if(dist == 2 * t)ans++;
        else if(dist > 2 * t)ans += 2;
    }
    cout << ans << endl;
    return 0;
}