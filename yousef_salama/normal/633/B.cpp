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
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int m;
int main(){
    scanf("%d", &m);
    
    vector <int> r;
    for(int n = 1; m >= 0; n++){
        int c = n;
        while((c % 5) == 0){
            c /= 5;
            m--;
        }
        
        if(m == 0)r.push_back(n);
    }
    
    printf("%d\n", r.size());
    for(int i = 0; i < r.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", r[i]);
    }
    printf("\n");
    
    return 0;
}