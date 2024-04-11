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
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        a[i] = tolower(a[i]);
    for(int i = 0; i < b.size(); i++)
        b[i] = tolower(b[i]);
    if(a == b)cout << 0 << endl;
    else if(a < b)cout << -1 << endl;
    else cout << 1 << endl;
    return 0;
}