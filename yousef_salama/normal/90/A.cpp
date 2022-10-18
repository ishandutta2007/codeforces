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
using namespace std;
int main(){
    vector <int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int res = 30;
    while(v[0] > 0 || v[1] > 0 || v[2] > 0){
        v[res % 3] -= 2;
        res++;
    }
    cout << res - 1 << endl;
    return 0;
}