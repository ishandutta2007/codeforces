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
#include <unordered_map>
using namespace std;

int h, w, q, h1, w1, h2, w2, ps[505][505];
char s[505][505];
int main(){
    scanf("%d %d", &h, &w);
    for(int i = 0; i < h; i++)
        scanf("%s", s[i]);

    for(int i = 0; i < h; i++)
    for(int j = 0; j < w; j++){
        if((i == 0) && (j == 0))ps[i][j] = 0;
        else if(i == 0){
            ps[i][j] = ps[i][j - 1];
            ps[i][j] += (s[i][j] == '.') && (s[i][j - 1] == '.');
        }else if(j == 0){
            ps[i][j] = ps[i - 1][j];
            ps[i][j] += (s[i][j] == '.') && (s[i - 1][j] == '.');
        }else{
            ps[i][j] += ps[i - 1][j];
            ps[i][j] += ps[i][j - 1];
            ps[i][j] -= ps[i - 1][j - 1];
            
            ps[i][j] += (s[i][j] == '.') && (s[i][j - 1] == '.');
            ps[i][j] += (s[i][j] == '.') && (s[i - 1][j] == '.');
        }
    }

    scanf("%d", &q);
    while(q--){
        scanf("%d %d %d %d", &h1, &w1, &h2, &w2);
        h1--, w1--, h2--, w2--;

        int r = ps[h2][w2];
        if(h1 > 0)r -= ps[h1 - 1][w2];
        if(w1 > 0)r -= ps[h2][w1 - 1];
        if((h1 > 0) && (w1 > 0))r += ps[h1 - 1][w1 - 1];

        for(int i = h1; i <= h2; i++)
            if((w1 > 0) && (s[i][w1] == '.') && (s[i][w1 - 1] == '.'))
                r--;
        for(int j = w1; j <= w2; j++)
            if((h1 > 0) && (s[h1][j] == '.') && (s[h1 - 1][j] == '.'))
                r--;
        printf("%d\n", r);
    }

    return 0;
}