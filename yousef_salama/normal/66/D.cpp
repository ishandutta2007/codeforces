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
int main(){
    cin >> n;
    if(n == 2)cout << -1 << endl;
    else{
        cout << 15 << endl << 10 << endl;
        for(int i = 1; i <= n - 2; i++)
            cout << 6 * i << endl;
    }
    return 0;
}