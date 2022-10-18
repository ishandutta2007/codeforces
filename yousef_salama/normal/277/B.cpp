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

int n, m;
int main(){
    scanf("%d %d", &n, &m);
    
    if(m == 3 && n == 4){
        printf("0 0\n");
        printf("3 0\n");
        printf("0 3\n");
        printf("1 1\n");
    }else if(m == 3 && n > 4)printf("-1\n");
    else{
        for(int i = 0; i < m; i++)
            printf("%d %d\n", i, 10000000 + i * i);
        
        for(int i = 0; i < (n - m); i++){
            printf("%d %d\n", i, - (10000000 + i * i));
        }
    }
    return 0;
}