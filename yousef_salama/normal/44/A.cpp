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
int N, ans = 0, flag;
char s[105][2][12];
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s %s", &s[i][0], &s[i][1]);
        flag = 1;
        for(int j = 0; j < i; j++)
            if(strcmp(s[j][0], s[i][0]) == 0 && strcmp(s[j][1], s[i][1]) == 0)
                flag = 0;
        ans += flag;
    }
    printf("%d\n", ans);
    return 0;
}