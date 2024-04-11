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
char s[105], a[] = "hello";
int i, j;
int main(){
    scanf("%s", &s);
    for(i = 0, j = 0; i < strlen(s) && j < strlen(a); i++)
        if(s[i] == a[j])j++;
    if(j == 5)printf("YES\n");
    else printf("NO\n");
    return 0;
}