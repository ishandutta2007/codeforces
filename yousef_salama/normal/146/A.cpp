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
int N, flag = 0, sum[] = {0, 0};
char s[50];
int main(){
    scanf("%d", &N);
    scanf("%s", &s);
    for(int i = 0; i < N; i++){
        flag |= !(s[i] == '4' || s[i] == '7');
        sum[i >= (N / 2)] += s[i] - '0';
    }
    if(flag || sum[0] != sum[1])printf("NO\n");
    else printf("YES\n");
    return 0;
}