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
#include <string.h>
using namespace std;
int main(){
    int n, i, j;
    cin >> n >> i >> j;
    i--;j--;
    if(((i == n / 2) || (i == n / 2 - 1)) && ((j == n / 2) || (j == n / 2 - 1)))cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}