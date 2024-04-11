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
#define FOR(i,n) for(int i =0;i<n;i++)
using namespace std;
int cnt = 0, g[15][15][15];
bool v[15][15][15];
int a[] = {0,0,0,0,1,-1};
int w[] = {0,0,1,-1,0,0};
int e[] = {1,-1,0,0,0,0};
void dfs(int k, int x, int j, int l, int r, int c){
    cnt++;
    v[k][x][j] = 1;
    for(int i = 0; i < 6; i++)
        if(k + a[i] >= 0 && x + w[i] >= 0 && j + e[i] >= 0 && k + a[i] < l && x + w[i] < r && j + e[i] < c){
            if(!v[k + a[i]][x + w[i]][j + e[i]] && !g[k + a[i]][x + w[i]][j + e[i]]){
                dfs(k + a[i], x + w[i], j + e[i], l, r, c);
            }
        }
}
int main(){
//    freopen("a.in","r",stdin);
    int l, r, c;
    cin >> l >> r >> c;
    char s[c];
    for(int k = 0; k < l; k++)
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                cin >> s[j];
                g[k][i][j] = s[j] == '.'?0:1;
            }
    int x, y;
    cin >> x >> y;
    x--;    
    y--;
    int z = 0;
    for(int k = 0; k < l; k++)
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                v[k][i][j] = 0;
    dfs(z, x, y, l, r, c);
    cout << cnt << endl;
    return 0;
}