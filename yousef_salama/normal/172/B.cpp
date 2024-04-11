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
int a, b, m, r, i, H[100005];
int main(){
    cin >> a >> b >> m >> r;
    
    memset(H, -1, sizeof H);
    i = 1;
    while(true){
        r = (a * r + b) % m;
        if(H[r] != -1){
            cout << i - H[r] << endl;
            break;
        }
        H[r] = i++;
    }
    return 0;
}