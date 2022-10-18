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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
#define MOD 1000000007
using namespace std;

int n, s[500005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)scanf("%d", &s[i]);
    sort(s, s + n);
    
    int j = 0;
    for(int i = n / 2; i < n; i++){
        if(j < n / 2){
            if(s[j] * 2 <= s[i])j++;
        }else break;
    }
    printf("%d\n", n - j);
    
    return 0;
}