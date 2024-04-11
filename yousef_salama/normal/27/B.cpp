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

#include <ext/hash_set>
#include <ext/hash_map>

using namespace __gnu_cxx;
int g[55][55];
bool v[55];
int main(){
    int n;
    cin >> n;
    int g[n][n];
    memset(g, 0, sizeof g);
    for(int i = 0; i < n; i++)
        g[i][i] = 0;
    for(int i = 0; i < (n * (n - 1)) / 2 - 1; i++){
        int x, y;
        cin >> x >> y;
        g[x - 1][y - 1] = 1;
    }
    for(int i = 0; i < n; i++)
        v[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(!g[i][j] && !g[j][i]){
                for(int k = 0; k < n; k++){
                    if(g[i][k] && g[k][j]){
                        cout << i + 1 << ' ' << j + 1 << endl;
                        return 0;
                    }
                }
                cout << j + 1 << ' ' << i + 1 << endl;
            }
    return 0;
}