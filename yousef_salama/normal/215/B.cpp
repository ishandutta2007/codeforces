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
int n, m, k;
double x, MaxR1, y[5005], MinP2, A, B;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        MaxR1 = max(x, MaxR1);
    }
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> y[i];
    cin >> k;
    MinP2 = 1 << 30;
    for(int i = 0; i < k; i++){
        cin >> x;
        MinP2 = min(MinP2, x);
    }
    cin >> A >> B;
    double MaxR2 = 0.0;
    for(int i = 0; i < m; i++){
        double cur = sqrt((MaxR1 * MaxR1 * y[i] * B) / (y[i] * B + MinP2 * A));
        MaxR2 = max(MaxR2, cur);
    }
    printf("%.12f\n", MaxR2);
    return 0;
}