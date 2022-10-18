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
#include <string.h>
using namespace std;
int w;
char s[][5] = {"NO", "YES"};
int main(){
    scanf("%d", &w);
    printf("%s\n", s[(w % 2 == 0) && (w != 2)]);
    return 0;
}