//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

const int MAXN = 5005;

int n, m, d[MAXN][MAXN];
char g[MAXN][MAXN];

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%s", g[i]);

    for(int i = 0; i < n; i++)
    for(int j = m - 1; j >= 0; j--){
        if(g[i][j] == '0')d[i][j] = 0;
        else{
            d[i][j] = 1;
            if(j < m - 1)d[i][j] += d[i][j + 1];
        }
    }
    
    int res = 0;
    for(int L = 0; L < m; L++){
        vector <int> rows;
        for(int i = 0; i < n; i++)
            rows.push_back(d[i][L]);
        sort(rows.rbegin(), rows.rend());
        
        int b = rows.size();
        for(int a = 1; L + a <= m; a++){
            while(b > 0 && rows[b - 1] < a)b--;
            res = max(res, a * b);
        }
    }
    printf("%d\n", res);
    
    return 0;
}