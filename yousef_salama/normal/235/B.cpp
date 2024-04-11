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
#define MOD 1000000007
using namespace std;
int n;
double p[100005], s[100005], sum;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        sum += p[i];
    }
    s[0] = 0;
    for(int i = 1; i < n; i++){
        s[i] = (s[i - 1] + p[i - 1]) * p[i];
        sum += s[i] * 2;
    }
    printf("%.15f\n",  sum);
    return 0;
}