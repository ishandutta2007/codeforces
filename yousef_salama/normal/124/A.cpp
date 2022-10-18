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
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int ans = 0;
    for(int i = 0; i <= b; i++){
        int next = n - i - 1;
        if(next >= a)ans++;
    }
    cout << ans << endl;
    return 0;
}