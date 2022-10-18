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
#define MAXN 100005
using namespace std;
char s[MAXN];
int N;
int main(){
    scanf("%s", s);
    N = strlen(s);
    
    deque <char> d;
    for(int i = 0; i < N; i++){
        while(!d.empty() && d.back() < s[i])d.pop_back();
        d.push_back(s[i]);
    }
    while(!d.empty()){
        printf("%c", d.front());
        d.pop_front();
    }
    printf("\n");
    return 0;
}