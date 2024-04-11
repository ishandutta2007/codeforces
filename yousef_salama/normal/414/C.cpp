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

int N, n, m, qi, a[1 << 20], max_level;
long long b[25], c[25];

vector <int> mergesort(int lvl, int L, int R){
    if(L == R){
        max_level = lvl;
        
        vector <int> ret;
        ret.push_back(a[L]);
        
        return ret;
    }else{
        int mid = (L + R) / 2;
        
        vector <int> ap = mergesort(lvl + 1, L, mid);
        vector <int> bp = mergesort(lvl + 1, mid + 1, R);
        
        for(int i = 0; i < ap.size(); i++){
            c[lvl] += upper_bound(bp.begin(), bp.end(), ap[i]) - lower_bound(bp.begin(), bp.end(), ap[i]);
        }
        
        int j = 0;
        for(int i = 0; i < ap.size(); i++){
            while(j < bp.size()){
                if(bp[j] < ap[i])j++;
                else break;
            }
            b[lvl] += j;
        }
        
        vector <int> ret;
        merge(ap.begin(), ap.end(), bp.begin(), bp.end(), back_inserter(ret));
        
        return ret;
    }
}
int main(){
    scanf("%d", &n);
    
    N = 1 << n;
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);

    mergesort(0, 0, N - 1);
    
    scanf("%d", &m);
    while(m--){
        scanf("%d", &qi);
        
        int clvl = n - qi;
        for(int i = clvl; i < max_level; i++){
            long long parts = (1 << i);
            long long X = (1 << (n - i));
            
            long long total_pairs = parts * (X / 2) * (X / 2);

            b[i] = total_pairs - b[i] - c[i];
        }

        long long res = 0;
        for(int i = 0; i < max_level; i++)
            res += b[i];
        printf("%I64d\n", res);
    }
    return 0;
}