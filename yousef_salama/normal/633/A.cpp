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

int a, b, c;
int main(){
    scanf("%d %d %d", &a, &b, &c);
    for(int x = 0; x * a <= c; x++){
        if((c - x * a) % b == 0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    
    return 0;
}