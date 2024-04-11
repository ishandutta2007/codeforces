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

char s[10][10];
bool visited[10][10][105];

int di[] = {0, 1, 1, 1, 0, 0, -1, -1, -1, 0};
int dj[] = {0, -1, 0, 1, -1, 1, -1, 0, 1, 0};


bool isvalid(int i, int j, int k){
    if(i < 0 || i >= 8)return false;
    if(j < 0 || j >= 8)return false;
    
    return !(i - k >= 0 && s[i - k][j] == 'S');
}
bool dfs(int i, int j, int k){
    if(i == 0 && j == 7)return true;
    if(k > 100 || visited[i][j][k])return false;
    
    visited[i][j][k] = true;

    for(int dir = 0; dir < 9; dir++){
        int ni = i + di[dir], nj = j + dj[dir];
        
        if(isvalid(ni, nj, k + 1) && isvalid(ni, nj, k)){
            if(dfs(ni, nj, k + 1))return true;
        }
    }
    return false;
}
int main(){
    for(int i = 0; i < 8; i++)
        scanf("%s", s[i]);
    
    if(dfs(7, 0, 0))printf("WIN\n");
    else printf("LOSE\n");
    return 0;
}