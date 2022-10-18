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

const int MAXN = 1000005;

int n, a[MAXN], d[MAXN][5];

int counts(int i, int j, int c){
    if(i > j)return 0;
    
    int ret = d[j][c];
    if(i > 0)ret -= d[i - 1][c];
    
    return ret;
}
int sum(int i, int j){
    int ret = 0;
    for(int c = 0; c <= 4; c++)
        ret += counts(i, j, c) * c;
    return ret;
}

int main(){
//    int d[] = {0, 3, 4};
//    for(int x0 = 0; x0 <= 4; x0++)
//    for(int y0 = x0 + 1; y0 <= 4; y0++){
//        for(int x1 = 0; x1 < 3; x1++)
//        for(int y1 = x1 + 1; y1 < 3; y1++){
//            int s1 = abs(x0 - d[x1]) + abs(y0 - d[y1]);
//            int s2 = abs(x0 - d[y1]) + abs(y0 - d[x1]);
//            
//            if(s1 > s2)cout << "wrong" << endl;
//        }
//    }
    
    scanf("%d", &n);

    int s = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        s += a[i];
    }
    sort(a, a + n);
    
    for(int i = 0; i < n; i++){
        d[i][a[i]] = 1;
        if(i > 0){
            for(int j = 0; j <= 4; j++)
                d[i][j] += d[i - 1][j];
        }
    }
    
    int res = 1 << 30;
    for(int C = 0; C <= n; C++){
        if(4 * C < s)continue;
        
        int c3 = 4 * C - s;
        int c4 = C - c3;
        if(c3 <= C){
            int curs = 0;
            
            curs += sum(0, n - C - 1);
            curs += 4 * c4 - sum(n - c4, n - 1);
            
            for(int c = 0; c <= 4; c++){
                if(c == 3)continue;
                
                if(c < 3){
                    curs += counts(n - C, n - c4 - 1, c) * (3 - c);
                }else{
                    curs += counts(n - C, n - c4 - 1, c) * (c - 3);
                }
            }
            
            res = min(res, curs);
        }
    }
    if(res == 1 << 30)printf("-1\n");
    else printf("%d\n", res / 2);
    
    return 0;
}