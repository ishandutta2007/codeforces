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

int n, a[100005], m, wi, hi;
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    long long maxheight = 0;
    
    scanf("%d", &m);
    while(m--){
        scanf("%d %d", &wi, &hi);
        wi--;
        
        long long curheight = max((long long)a[wi], maxheight);
        printf("%I64d\n", curheight);
        
        maxheight = max(maxheight, curheight + hi);
    }
    return 0;
}