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
#define MOD 1000003
using namespace std;
int n, m, u, l, U[500005], L[500005];
string g[500005];
int x[] = {1, 1, 0, 0};
int y[] = {1, 0, 0, 1};
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> g[i];
    memset(U, -1, sizeof U);
    memset(L, -1, sizeof L);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        if(g[i][j] != '.'){
            if(j % 2 == 0){
                if(L[i] == -1 || L[i] == x[g[i][j] - '0' - 1])
                    L[i] = x[g[i][j] - '0' - 1];
                else{
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(L[i] == -1 || L[i] == 1 - x[g[i][j] - '0' - 1])
                    L[i] = 1 - x[g[i][j] - '0' - 1];
                else{
                    cout << 0 << endl;
                    return 0;
                }

            }
            if(i % 2 == 0){
                if(U[j] == -1 || U[j] == y[g[i][j] - '0' - 1])
                    U[j] = y[g[i][j] - '0' - 1];
                else{
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(U[j] == -1 || U[j] == 1 - y[g[i][j] - '0' - 1])
                    U[j] = 1 - y[g[i][j] - '0' - 1];
                else{
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    u = 0, l = 0;
    for(int i = 0; i < n; i++)
        if(L[i] == -1)l++;
    for(int i = 0; i < m; i++)
        if(U[i] == -1)u++;

    int ans = 1;
    for(int i = 0; i < (l + u); i++)
        ans = (2 * ans) % MOD;
    cout << ans << endl;
    return 0;
}