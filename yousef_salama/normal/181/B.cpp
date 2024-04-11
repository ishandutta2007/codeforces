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
int n, x[3005], y[3005];
set < pair <int, int> > S;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        S.insert(make_pair(x[i] * 2, y[i] * 2));
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
        if(S.count(make_pair(x[i] + x[j], y[i] + y[j])))ans++;
    cout << ans << endl;
    return 0;
}