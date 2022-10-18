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
int N, M, k, xc, yc, xi, yi;
long long ans = 0;
int main(){
    cin >> N >> M >> xc >> yc >> k;
    while(k--){
        int a = INT_MAX, b = INT_MAX;
        cin >> xi >> yi;
        if(xi > 0){
            a = (N - xc) / abs(xi);
        }else if(xi < 0){
            a = (xc - 1) / abs(xi);
        }
        if(yi > 0){
            b = (M - yc) / abs(yi);
        }else if(yi < 0){
            b = (yc - 1) / abs(yi);
        }
        int Mi = min(a, b);
        ans += Mi;
        xc += Mi * xi;
        yc += Mi * yi;
    }
    cout << ans << endl;
    return 0;
}