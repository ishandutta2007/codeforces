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
int n;
long long x, y;
long long cur;
int main(){
    cin >> n >> x >> y;
    if(n - 1 >= y){
        cout << -1 << endl;
        return 0;
    }
    cur += (y - (n - 1)) * (y - (n - 1)) + (n - 1);
    if(cur < x){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; i++)
        cout << 1 << endl;
    cout << (y - (n - 1)) << endl;
    return 0;
}