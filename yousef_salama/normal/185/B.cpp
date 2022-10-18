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

int S, a, b, c;
int main(){
    scanf("%d %d %d %d", &S, &a, &b, &c);
    
    if((a + b + c) == 0){
        printf("%.15f %.15f %.15f\n", S / 3.0, S / 3.0, S / 3.0);
    }else{
        printf("%.15f %.15f %.15f\n", 
            1.0 * a * S / (a + b + c), 1.0 * b * S / (a + b + c), 1.0 * c * S / (a + b + c));
    }
    
    return 0;
}