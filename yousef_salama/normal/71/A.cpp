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
int N;
char s[105];
int main(){
    scanf("%d", &N);
    while(N--){
        scanf("%s", &s);
        if(strlen(s) > 10)printf("%c%d%c\n", s[0], strlen(s) - 2, s[strlen(s) - 1]);
        else printf("%s\n", s);
    }
    return 0;
}