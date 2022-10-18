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
    int n, t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 1)cout << 0 << endl;
        else cout << n - 2 << endl;
    }
    return 0;
}