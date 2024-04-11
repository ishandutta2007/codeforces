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
#include <string.h>
using namespace std;
int main(){
//    freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    string v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int i = 0, j = 0, cnt = 0, dir = 1;
    while(i < n){
        v[i][j] = 'G';
        bool cont = false;
        if(j >= m || j < 0)cont = true;
        else{
            for(int k = j + dir; k < m && k >= 0; k += dir){
                if(v[i][k] == 'W')cont = true;
                if(i < n - 1){
                    if(v[i + 1][k] == 'W')cont = true;
                }
            }
        }
        if(i < n - 1 && !cont){
            bool found = 0;
            for(int curI = i + 1; curI < n; curI++)
                for(int curJ = 0; curJ < m; curJ++)
                    if(v[curI][curJ] == 'W')found = 1;
            if(!found){
                break;
            }
        }
        if(!cont){
            dir = (dir == 1?-1:1);
            i++;
            if(i >= n)break;
            cnt++;
        }
        else{
            j += dir;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}