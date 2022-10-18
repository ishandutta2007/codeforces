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
int x;
string toString(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
bool correct(int d, int a){
    string v = toString(d), u = toString(a);
    for(int i = 0; i < v.size(); i++)
    for(int j = 0; j < u.size(); j++)
        if(v[i] == u[j])return true;
    return false;
}
int main(){
    scanf("%d", &x);
    int ans = 0;
    for(int d = 1; d * d <= x; d++)if(x % d == 0){
        if(correct(d, x))ans++;
        if(d * d != x && correct(x / d, x))ans++;
    }
    printf("%d\n", ans);
    return 0;
}