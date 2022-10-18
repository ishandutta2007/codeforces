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

int main(){
    int n, m;
    cin >> n >> m;
    string g[n];
    for(int i = 0; i < n; i++)
        cin >> g[i];
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++)
            if(g[i][j] != g[i][j - 1]){
                cout << "NO" << endl;
                return 0;
            }
    }
    for(int i = 0; i < m; i++){
        for(int j = 1; j < n; j++)
            if(g[j][i] == g[j - 1][i]){
                cout << "NO" << endl;
                return 0;
            }
    }
    cout << "YES" << endl;
    return 0;
}