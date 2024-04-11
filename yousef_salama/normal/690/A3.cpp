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
#include <complex>
#include <unordered_map>

using namespace std;


int T, N, R;
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &R);
        R--;
        
        vector <int> v(N - 1);
        
        for(int i = 0; i < (N - 1); i++){
            scanf("%d", &v[i]);
            v[i]--;
            
            R = (R - v[i] + N) % N;
        }
        
        printf("%d\n", R + 1);
    }
    
}