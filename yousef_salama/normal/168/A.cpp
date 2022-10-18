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
int n, x, y;
int main(){
    scanf("%d %d %d", &n, &x, &y);
    if(x * 100 >= n * y)printf("0\n");
    else printf("%d\n", (n * y + 99) / 100 - x);
    return 0;
}