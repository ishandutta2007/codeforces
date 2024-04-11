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
int n, m, a, b;
bool g[1005][1005];
int main(){
    cin >> n >> m;
    int ans = -1, cur = 1;
    while(m--){
        cin >> a >> b;
        g[--a][--b] = true;
        bool found = false;
        for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
           if(a - i >= 0 && b - j >= 0 && a - i + 2 < n && b - j + 2 < n){
               bool wrong = false;
               for(int p1 = a - i; p1 < a - i + 3; p1++)
               for(int p2 = b - j; p2 < b - j + 3; p2++)
                   if(!g[p1][p2])wrong = true;
               if(!wrong)found = true;
           }
        }
        if(ans == -1 && found)ans = cur;
        cur++;
    }
    cout << ans << endl;
    return 0;
}