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

char s[5005];
int N, g[5005];
int main(){
    scanf("%s", s);
    N = strlen(s);
    
    g[0] = 0;
    for(int len = 1; len <= N; len++){
        vector <int> v;
        for(int i = 0; i < len; i++){
            int x = g[max(0, i - 1)] ^ g[max(0, len - (i + 2))];
            v.push_back(x);
        }
        v.push_back(-1);
        v.push_back(1 << 30);
        sort(v.begin(), v.end());
        
        for(int i = 0; i < (v.size() - 1); i++){
            if(v[i] + 1 < v[i + 1]){
                g[len] = v[i] + 1;
                break;
            }
        }
    }
    
    vector <int> p;
    for(int i = 1; i < N - 1; i++)
        if(s[i - 1] == s[i + 1])p.push_back(i);
    
    int curX = 0;
    for(int i = 0; i < p.size(); ){
        int j = i;
        while((j + 1 < p.size()) && (p[j] + 1 == p[j + 1]))
            j++;
        
        curX ^= g[p[j] - p[i] + 1];
        i = j + 1;
    }

    
    if(curX != 0){
        printf("First\n");
        
        for(int i = 0; i < p.size(); ){
            int j = i;
            while((j + 1 < p.size()) && (p[j] + 1 == p[j + 1]))
                j++;
            
            curX ^= g[p[j] - p[i] + 1];
            for(int k = 0; k < (p[j] - p[i] + 1); k++){
                curX ^= g[max(0, k - 1)] ^ g[max(0, (p[j] - p[i] + 1) - (k + 2))];
                if(curX == 0){
                    printf("%d\n", p[i] + k + 1);
                    return 0;
                }
                curX ^= g[max(0, k - 1)] ^ g[max(0, (p[j] - p[i] + 1) - (k + 2))];
            }
            curX ^= g[p[j] - p[i] + 1];
            i = j + 1;
        }
    }else printf("Second\n");
    
    return 0;
}