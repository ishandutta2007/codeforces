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

char s[1000005];
int sl[1000005], sr[1000005], l, r;
int main(){
    scanf("%s", s);
    for(int i = 0; s[i]; i++){
        if(s[i] == 'l')sl[l++] = i;
        else sr[r++] = i;
    }
    
    for(int i = 0; i < r; i++)
        printf("%d\n", sr[i] + 1);
    for(int i = l - 1; i >= 0; i--)
        printf("%d\n", sl[i] + 1);
    return 0;
}