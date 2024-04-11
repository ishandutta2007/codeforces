#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
using namespace std;
int n, x[25], y[25], dp[1 << 24];
short path[1 << 24], xi[1 << 24], yi[1 << 24];
int dist(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}
void printPath(int mask){
    if(mask == (1 << n) - 1)return;
    if(path[mask] == 1){
        cout << ' ' << xi[mask] << ' ' << 0;
        printPath(mask | (1 << (xi[mask] - 1)));
    }
    else if(path[mask] == 2){
        cout << ' ' << xi[mask] << ' ' << yi[mask] << ' ' << 0;
        printPath(mask | (1 << (xi[mask] - 1)) | (1 << (yi[mask] - 1)));
    }
}
int main(){
    cin >> x[0] >> y[0] >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    memset(dp, 63, sizeof dp);
    dp[(1 << n) - 1] = 0;
    for(int mask = (1 << n) - 2; mask >= 0; mask--){
        for(int i = 1; i <= n; i++){
            if(!(mask & (1 << (i - 1)))){
                for(int j = i; j <= n; j++){
                    if(!(mask & (1 << (j - 1)))){
                        int cur = dp[mask | (1 << (i - 1)) | (1 << (j - 1))] +
                            dist(0, i) + dist(i, j) + dist(0, j);
                        if(cur < dp[mask]){
                            dp[mask] = cur;
                            path[mask] = !(i == j) + 1;
                            xi[mask] = i;
                            yi[mask] = j;
                        }
                    }
                }
                break;
            }
        }
    }
    cout << dp[0] << endl;
    cout << 0;
    printPath(0);
    cout << endl;
    return 0;
}