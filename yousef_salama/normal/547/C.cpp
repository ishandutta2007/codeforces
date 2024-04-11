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

const int MAXN = 200005;
const int MAXV = 500005;
int n, q, ai[MAXN], xi, v[MAXN], c[MAXV];

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%d", &ai[i]);
    
    long long s = 0, g = 0;
    while(q--){
        scanf("%d", &xi);
        xi--;
        
        vector <int> d;
        
        int y = ai[xi];
        for(int j = 2; j * j <= y; j++){
            if((y % j) == 0)d.push_back(j);
            while((y % j) == 0)y /= j;
        }
        if(y > 1)d.push_back(y);
        
        if(v[xi]){
            for(int m = 1; m < (1 << d.size()); m++){
                int di = 1;
                for(int i = 0; i < d.size(); i++)
                    if(m & (1 << i))di *= d[i];
                
                if(__builtin_popcount(m) & 1)c[di]--;
                else c[di]--;
            }
            s--;
            v[xi] = 0;
            
            long long r = 0;
            for(int m = 1; m < (1 << d.size()); m++){
                int di = 1;
                for(int i = 0; i < d.size(); i++)
                    if(m & (1 << i))di *= d[i];
                
                if(__builtin_popcount(m) & 1)r += c[di];
                else r -= c[di];
            }
            g -= r;
        }else{
            long long r = 0;
            for(int m = 1; m < (1 << d.size()); m++){
                int di = 1;
                for(int i = 0; i < d.size(); i++)
                    if(m & (1 << i))di *= d[i];
                
                if(__builtin_popcount(m) & 1)r += c[di];
                else r -= c[di];
            }
            g += r;
            
            for(int m = 1; m < (1 << d.size()); m++){
                int di = 1;
                for(int i = 0; i < d.size(); i++)
                    if(m & (1 << i))di *= d[i];
                
                if(__builtin_popcount(m) & 1)c[di]++;
                else c[di]++;
            }
            s++;
            v[xi] = 1;
        }
        
        printf("%I64d\n", (s * (s - 1) / 2) - g);
    }
    return 0;
}