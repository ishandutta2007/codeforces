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
int n, b, a[105];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
        scanf("%d", &b);
        if(b == -1)continue;
        
        for(int x = 0; x < 31; x++){
            if(b & (1 << x)){
                a[i] |= 1 << x;
                a[j] |= 1 << x;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}