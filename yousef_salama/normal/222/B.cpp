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
int n, m, k, g[1005][1005], row[1005], col[1005], a, b;
char c;
int main(){
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &g[i][j]);
    for(int i = 0; i < n; i++)
        row[i] = i;
    for(int i = 0; i < m; i++)
        col[i] = i;
    while(k--){
        cin >> c >> a >> b;
        
        if(c == 'c'){
            swap(col[a - 1], col[b - 1]);
        }else if(c == 'r'){
            swap(row[a - 1], row[b - 1]);
        }else{
            printf("%d\n", g[row[a - 1]][col[b - 1]]);
        }
    }
    return 0;
}