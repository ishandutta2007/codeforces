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
    string s = "ROY", a = "GBIV";
    int n;
    cin >> n;
    cout << s;
    for(int i = 0; i < n - 3; i++)
        cout << a[i % 4];
    cout << endl;
    return 0;
}