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
int n, m, x[105], y[105];
string g[105];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> g[i];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(g[i][j] == '*'){
            x[i]++;
            y[j]++;
        }
    int r, c;
    for(int i = 0; i < n; i++)
        if(x[i] == 1)r = i;
    for(int i = 0; i < m; i++)
        if(y[i] == 1)c = i;
    cout << r + 1 << ' ' << c + 1 << endl;
    return 0;
}