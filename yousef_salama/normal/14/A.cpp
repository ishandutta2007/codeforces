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
#define FOR(i, n) for(int i = 0; i < n; i++)
using namespace std;
int main(){
//    freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    int fi = INT_MAX, fj = INT_MAX, ei = INT_MIN, ej = INT_MIN;
    char s[m], g[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[j];
            g[i][j] = s[j];
            if(s[j] == '*'){
                fi = min(i, fi);
                fj = min(j, fj);
                ei = max(i, ei);
                ej = max(j, ej);
            }
        }
    }
    for(int i = fi; i <= ei; i++){
        for(int j = fj; j <= ej; j++){
            cout << g[i][j];
        }
        cout << endl;
    }
    return 0;
}