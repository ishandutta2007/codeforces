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
char s[100005], a[15][15];
int n, r[100005];
int main(){
    scanf("%s %d", s, &n);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    int j = 0;
    for(int i = 0; s[i]; i++){
        for(int k = 0; k < n; k++){
            int L = strlen(a[k]);
            if(L <= i + 1){
                bool ok = true;
                for(int p = i - L + 1; p <= i; p++)
                    if(s[p] != a[k][p - (i - L + 1)])ok = false;
                
                if(ok)j = max(j, i - L + 2);
            }
        }
        r[i] = i - j + 1;
    }
    int ind = max_element(r, r + (strlen(s))) - r;
    printf("%d %d\n", r[ind], r[ind] ? (ind - r[ind] + 1) : ind);
    return 0;
}