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
#include <cstring>
#include <sstream>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    printf("%d", n);
    for(int i = 1; i < n; i++)
        printf(" %d", i);
    printf("\n");
    return 0;
}