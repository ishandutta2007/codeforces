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
int ans;
int n, p;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        ans += p;
    }
    printf("%.12f\n", (double)ans / n);
    return 0;
}