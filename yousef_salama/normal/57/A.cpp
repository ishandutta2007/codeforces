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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
using namespace std;
int n, X1, Y1, X2, Y2, d[1005][1005];
bool valid(int x, int y){
    if((x == 0 || x == n) && (0 <= y && y <= n))return true;
    if((y == 0 || y == n) && (0 <= x && x <= n))return true;
    return false;
}
int main(){
    scanf("%d %d %d %d %d", &n, &X1, &Y1, &X2, &Y2);
    
    queue < pair <int, int> > q;
    memset(d, -1, sizeof d);
    d[X1][Y1] = 0;
    q.push(make_pair(X1, Y1));
    
    while(!q.empty()){
        pair <int, int> a = q.front();
        q.pop();
        
        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, 1, -1};
        
        for(int dir = 0; dir < 4; dir++){
            int nx = a.first + di[dir], ny = a.second + dj[dir];
            if(valid(nx, ny) && d[nx][ny] == -1){
                q.push(make_pair(nx, ny));
                d[nx][ny] = d[a.first][a.second] + 1;
            }
        }
    }
    printf("%d\n", d[X2][Y2]);
    return 0;
}