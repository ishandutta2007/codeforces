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
int a, b, r;
int main(){
    cin >> a >> b >> r;
    if(2 * r <= a && 2 * r <= b)cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}