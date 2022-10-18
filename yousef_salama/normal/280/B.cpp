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

int n, m, s[100005], a[100005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    
    a[m++] = s[0];
    
    int ans = 0;
    for(int i = 1; i < n; i++){
        while(m > 0 && s[i] > a[m - 1]){
            ans = max(ans, s[i] ^ a[m - 1]);
            m--;
        }
        if(m > 0)ans = max(ans, s[i] ^ a[m - 1]);
        a[m++] = s[i];
    }
    printf("%d\n", ans);
    return 0;
}