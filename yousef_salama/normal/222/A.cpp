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
int n, k, a[100005];
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    int cnt = 1;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] != a[i + 1])break;
        else cnt++;
    }
    if((n - cnt) < k)printf("%d\n", n - cnt);
    else printf("-1\n");
    return 0;
}