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
int a, b, c;
int main(){
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", b * c + (a - 1) * c + (a - 1) * b - (a - 1));
    return 0;
}