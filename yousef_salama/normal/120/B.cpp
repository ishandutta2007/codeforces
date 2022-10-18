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
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    k--;
    while(1){
        if(a[k] == 1){
            cout << k + 1 << endl;
            return 0;
        }
        k = (k + 1) % n;
    }
    return 0;
}