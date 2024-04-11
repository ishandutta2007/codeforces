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
#define oo 1 << 25
using namespace std;
int main(){
    int n, m, t;
    long long nCr[75][75], ans = 0;
    cin >> n >> m >> t;
    for(int i = 0; i < 75; i++)
        nCr[i][0] = 1;
    for(int i = 1; i < 75; i++)
        nCr[0][i] = 0;
    for(int i = 1; i < 75; i++)
        for(int j = 1; j < 75; j++)
            nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    for(int i = 0; i + 4 < t; i++)
        ans += nCr[n][4 + i] * nCr[m][t - (4 + i)];
    cout << ans << endl;
    return 0;
}