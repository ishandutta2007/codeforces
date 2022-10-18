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
int x, n;
int main(){
    cin >> x;
    if(x == 3)cout << 5 << endl;
    else{
        for(n = 1; ; n += 2)
            if((n * n + 1) / 2 >= x)break;
        cout << n << endl;
    }
    return 0;
}