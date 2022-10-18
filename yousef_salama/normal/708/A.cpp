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

char s[100005];
int N;

int main(){
    scanf("%s", s);
    N = strlen(s);
    
    int L, R;
    for(L = 0; L < N; L++)
        if(s[L] != 'a')break;
        
    if(L == N){
    	s[N - 1] = 'z';
        printf("%s\n", s);
        return 0;
    }
        
    for(R = L; R < N; R++)
        if(s[R] == 'a')break;
        
    for(int i = L; i < R; i++){
        if(s[i] == 'a')s[i] = 'z';
        else s[i]--;
    }
    
    printf("%s\n", s);
    
    return 0;
}